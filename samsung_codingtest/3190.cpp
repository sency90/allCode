#include <cstdio>
#include <deque>
using namespace std;
struct Coord{
	int x,y;
	bool operator==(const Coord & rhs) const {
		return x==rhs.x && y==rhs.y;
	}
};
deque<Coord> snake;
int an;
Coord a[101];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int turn_right(int dir) {
	return ++dir%4;
}
int turn_left(int dir) {
	return (--dir + 4)%4;
}

int n,dir;
bool dead = false;
int ans=0;
int simul(int sec, char c) {
	for(int i=0; i<sec; i++) {
		Coord nco = {snake.front().x+dx[dir], snake.front().y+dy[dir]};
		if(nco.x<=0 || nco.x>n || nco.y<=0 || nco.y>n) {
			dead = true;
			return i+1;
		}
		snake.push_front(nco);
		for(int j=1; j<snake.size(); j++) {
			if(snake[j] == nco) {
				dead = true;
				return i+1;
			}
		}

		bool eat_apple = false;
		for(int i=0; i<an; i++) {
			if(a[i] == nco) { //eat apple
				a[i] = a[--an];
				eat_apple = true;
				break;
			}
		}
		if(!eat_apple) snake.pop_back();
	}
	if(c == 'L') dir = turn_left(dir);
	else dir = turn_right(dir);
	return sec;
}
int main() {
	snake.push_front({1,1});
	scanf("%d%d", &n,&an);
	for(int i=0; i<an; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}

	int l; scanf("%d", &l);
	int ps=0, s;
	char c;
	for(int i=0; i<l; i++) {
		scanf("%d %c", &s, &c);
		if(!dead) ans+=simul(s-ps, c);
		ps = s;
	}
	if(!dead) ans+=simul(100, c);
	printf("%d\n", ans);
	return 0;
}
