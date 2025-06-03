#include <cstdio>
using namespace std;

int right[] = {6,3,0,7,4,1,8,5,2};
int left[] = {2,5,8,1,4,7,0,3,6};

struct Side{
	char arr[3][3];
	Side(){}
	Side(const Side & rhs) {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				arr[i][j] = rhs.arr[i][j];
			}
		}
	}

	int tmp[9];
	void rotate_right() {
		char *v = (char*)arr;
		for(int i=0; i<9; i++) {
			tmp[i] = v[right[i]];
		}
		for(int i=0; i<9; i++) {
			v[i] = tmp[i];
		}
	}

	void rotate_left() {
		char *v = (char*)arr;
		for(int i=0; i<9; i++) {
			tmp[i] = v[left[i]];
		}
		for(int i=0; i<9; i++) {
			v[i] = tmp[i];
		}
	}

	void fill_with(char c) {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				arr[i][j] = c;
			}
		}
	}

	void print() const {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				printf("%c", arr[i][j]);
			}
			puts("");
		}
	}
};

int chk[6][4][9] = {
	{
		{3,2,1,0,0,0,0,0,0}, //B
		{3,2,1,0,0,0,0,0,0}, //R
		{3,2,1,0,0,0,0,0,0}, //F
		{3,2,1,0,0,0,0,0,0}  //L
	}, //U
	{
		{0,0,0,0,0,0,1,2,3}, //F
		{0,0,0,0,0,0,1,2,3}, //R
		{0,0,0,0,0,0,1,2,3}, //B
		{0,0,0,0,0,0,1,2,3}  //L
	}, //D
	{
		{0,0,0,0,0,0,1,2,3}, //U
		{1,0,0,2,0,0,3,0,0}, //R
		{3,2,1,0,0,0,0,0,0}, //D
		{0,0,3,0,0,2,0,0,1}  //L
	}, //F
	{
		{3,2,1,0,0,0,0,0,0}, //U
		{1,0,0,2,0,0,3,0,0}, //L
		{0,0,0,0,0,0,1,2,3}, //D
		{0,0,3,0,0,2,0,0,1}  //R
	}, //B
	{
		{1,0,0,2,0,0,3,0,0}, //U
		{1,0,0,2,0,0,3,0,0}, //F
		{1,0,0,2,0,0,3,0,0}, //D
		{0,0,3,0,0,2,0,0,1}  //B
	}, //L
	{
		{0,0,3,0,0,2,0,0,1}, //U
		{1,0,0,2,0,0,3,0,0}, //B
		{0,0,3,0,0,2,0,0,1}, //D
		{0,0,3,0,0,2,0,0,1}  //F
	} //R
};

int tmp[4][4];
void rotate_clockwise(Side **p, int side_no) {
	p[4]->rotate_right();
	for(int z=0; z<4; z++) {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				int c = chk[side_no][z][i*3+j];
				if(c) {
					tmp[z][c] = p[z]->arr[i][j];
				}
			}
		}
	}

	for(int z=0; z<4; z++) {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				int c = chk[side_no][z][i*3+j];
				if(c) {
					p[z]->arr[i][j] = tmp[(z-1+4)%4][c];
				}
			}
		}
	}
}
void rotate_counterclockwise(Side **p, int side_no) {
	p[4]->rotate_left();
	for(int z=0; z<4; z++) {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				int c = chk[side_no][z][i*3+j];
				if(c) {
					//printf("[z:%d](%d,%d) ", z,i,j);
					tmp[z][c] = p[z]->arr[i][j];
				}
			}
		}
		//puts("");
	}

	for(int z=0; z<4; z++) {
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				int c = chk[side_no][z][i*3+j];
				if(c) {
					p[z]->arr[i][j] = tmp[(z+1)%4][c];
				}
			}
		}
	}
}
Side cube[6];
constexpr int U = 0;
constexpr int D = 1;
constexpr int F = 2;
constexpr int B = 3;
constexpr int L = 4;
constexpr int R = 5;

//U -> U B R F L
//D -> D F R B L
//F -> F U R D L
//B -> B D R U L
//L -> L U F D B
//R -> R U B D F

char dir_names[] = {'U', 'D', 'F', 'B', 'L', 'R'};
int side_order[6][5] = {
	{ B,R,F,L,U },
	{ F,R,B,L,D },
	{ U,R,D,L,F },
	{ U,L,D,R,B },
	{ U,F,D,B,L },
	{ U,B,D,F,R }
};

char order[256];
void init() {
	cube[U].fill_with('w');
	cube[D].fill_with('y');
	cube[F].fill_with('r');
	cube[B].fill_with('o');
	cube[L].fill_with('g');
	cube[R].fill_with('b');
}

char cmd[3];
int main() {
	int tc; scanf("%d", &tc);
	for(int i=0; i<6; i++) {
		order[(int)dir_names[i]] = i;
	}

	Side *p[5];
	while(tc--) {
		init();
		int n; scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", cmd);
			for(int j=0; j<5; j++) {
				p[j] = &cube[side_order[order[cmd[0]]][j]];
			}
			if(cmd[1] == '+') rotate_clockwise(p, order[cmd[0]]);
			else rotate_counterclockwise(p, order[cmd[0]]);
		}
		cube[U].print();
	}
	return 0;
}
