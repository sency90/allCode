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
};

void rotate_clockwise(Side **p) {
	p[0]->rotate_right();
	Side tmp = *p[0];
	for(int i=1; i<4; i++) {
		for(int j=0; j<3; j++) {
			p[i]->arr[2][j] = p[i+1]->arr[2][j];
		}
	}
	for(int j=0; j<3; j++) {
		p[4]->arr[2][j] = tmp.arr[2][j];
	}
}
void rotate_counterclockwise(Side **p) {
	p[0]->rotate_left();
	Side tmp = *p[4];
	for(int i=4; i>=1; i--) {
		for(int j=0; j<3; j++) {
			p[i]->arr[2][j] = p[i-1]->arr[2][j];
		}
	}
	for(int j=0; j<3; j++) {
		p[0]->arr[2][j] = tmp.arr[2][j];
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
	{ U,B,R,F,L },
	{ D,F,R,B,L },
	{ F,U,R,D,L },
	{ B,D,R,U,L },
	{ L,U,F,D,B },
	{ R,U,B,D,F }
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
		order[dir_names[i]] = i;
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
			if(cmd[1] == '+') rotate_clockwise(p);
			else rotate_counterclockwise(p);
		}

		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				printf("%c", p[U]->arr[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
