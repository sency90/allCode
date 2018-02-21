#include <stdio.h>
int v[513][513];
struct Co{
	int x,y;
	Co(){} Co(int x,int y):x(x),y(y){}
};
struct Block{
	Co co[3];
	Block(){}
	Block(Co a,Co b,Co c){
		co[0]=a,co[1]=b,co[2]=c;
	}
};

const Block b1(Co(0,1),Co(1,0),Co(1,1));
const Block b2(Co(0,0),Co(1,0),Co(1,1));
const Block b3(Co(0,0),Co(0,1),Co(1,1));
const Block b4(Co(0,0),Co(0,1),Co(1,0));
const Block b0;
const Block b[5]={b0,b1,b2,b3,b4};

inline void fillBlock(int x, int y, int k) {
	for(int i=0; i<3; i++) {
		int nx=x+b[k].co[i].x,ny=y+b[k].co[i].y;
		v[nx][ny]=k;
	}
}

int n,x,y;
inline bool isinc(int sx,int sy,int ex,int ey) {
	return sx<=x&&x<=ex&&sy<=y&&y<=ey;
}

void solve(int sx,int sy,int ex,int ey,int k) {
	if(ex-sx==1) {
		if(k==0) {
			if(v[sx][sy]<0) fillBlock(sx,sy,1);
			else if(v[sx][sy+1]<0) fillBlock(sx,sy,2);
			else if(v[sx+1][sy]<0) fillBlock(sx,sy,3);
			else fillBlock(sx,sy,4);
		} else {
			fillBlock(sx,sy,k);
		}
		return;
	}

	int ssx[5],ssy[5],eex[5],eey[5];
	int mx=(sx+ex)>>1,my=(sy+ey)>>1,t[5];

	ssx[4]=sx,ssy[4]=sy,eex[4]=mx,eey[4]=my;
	ssx[3]=sx,ssy[3]=my+1,eex[3]=mx,eey[3]=ey;
	ssx[2]=mx+1,ssy[2]=sy,eex[2]=ex,eey[2]=my;
	ssx[1]=mx+1,ssy[1]=my+1,eex[1]=ex,eey[1]=ey;

	if(k==0) {
		for(int i=1; i<=4; i++) t[i]=i;
		if(isinc(sx,sy,mx,my)) t[4]=0;
		else if(isinc(sx,my+1,mx,ey)) t[3]=0;
		else if(isinc(mx+1,sy,ex,my)) t[2]=0;
		else if(isinc(mx+1,my+1,ex,ey)) t[1]=0;

		for(int i=1; i<=4; i++) {
			solve(ssx[i],ssy[i],eex[i],eey[i],t[i]);
		}
	} else {
		for(int i=1; i<=4; i++) {
			if(k+i==5) solve(ssx[i],ssy[i],eex[i],eey[i],k);
			else solve(ssx[i],ssy[i],eex[i],eey[i],i);
		}
	}
	if(v[mx][my]) fillBlock(mx,my,1);
	else if(v[mx][my+1]) fillBlock(mx,my,2);
	else if(v[mx+1][my]) fillBlock(mx,my,3);
	else fillBlock(mx,my,4);
}
int main() {
	scanf("%d%d%d",&n,&x,&y);
	v[x][y]=-1;
	solve(0,0,n-1,n-1,0);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(v[i][j]<0) v[i][j]=0;
			printf("%d ",v[i][j]);
		} puts("");
	}
	return 0;
}
