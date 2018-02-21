extern int getNumber(int,int);
inline int min(int x,int y) { return x<y?x:y; }
inline int getSize(int dir) {
	int lo=0,hi=999999;
	while(lo<=hi) {
		int mid = (lo+hi)/2;
		int res = getNumber(dir,mid);
		if(res==0) hi=mid-1;
		else lo=mid+1;
	}
	return lo;
}
int d[1000002][2];
int card_find(int user_ans[]) {
	int osz = getSize(1);
	int csz = getSize(2);

	for(int i=0; i<=osz; i++) {
		d[i][0]=d[i][1]=-1;
	}

	int lo=0,hi=csz-1,s=0,cnt=0;

	while(lo<csz) {
		hi=min(lo+10000,csz-1);
		while(lo<=hi) {
			int mid = (lo+hi)>>1;
			int x,y;
			if(d[mid][1]<0) d[mid][1]=x=getNumber(2,mid);
			else x=d[mid][1];
			if(d[mid][0]<0) d[mid+s][0]=y=getNumber(1,mid+s);
			else y=d[mid+s][0];

			//int x=getNumber(2,mid),y=getNumber(1,mid+s);
			if(x==y && x!=0 && y!=0) lo=mid+1;
			else hi=mid-1;
		}

		int i=lo,j=lo+s;
		while(i<csz && j<osz) {
			int x,y;
			if(d[i][1]<0) d[i][1]=x=getNumber(2,i);
			else x=d[i][1];
			if(d[j][0]<0) d[j][0]=y=getNumber(1,j);
			else y=d[j][0];

			//int x=getNumber(2,i),y=getNumber(1,j);
			if(x!=y) {
				j++,s++;
				user_ans[cnt++]=y;
			} else {
				break;
			}
		}
	}
	for(int i=lo+s; i<osz; i++) {
		if(d[i][0]<0) user_ans[cnt++]=getNumber(1,i);
		else user_ans[cnt++]=d[i][0];
	}

	return cnt;
}
