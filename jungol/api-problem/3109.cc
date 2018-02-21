void assign(int *val,int x) {
	for(int i=3; i>=0; i--) {
		val[i]=x%10;
		x/=10;
	}
}
bool noAns[10001];
void tryBest(int suppose[]) {
	for(int i=0; i<10000; i++) noAns[i]=false;
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				for(int u=0; u<10; u++) {
					if(i==j || j==k || k==u || i==k || i==u || j==u) noAns[i*1000+j*100+k*10+u]=true;
				}
			}
		}
	}

	while(true) {
		for(int i=0; i<10000; i++) {
			if(noAns[i]) continue;
			assign(suppose,i);
			break;
		}

		Data res = query(suppose);
		if(res.strike == 4) return;

		int t[4];
		for(int i=0; i<10000; i++) {
			if(noAns[i]) continue;
			assign(t,i);
			int s=0,b=0;
			for(int j=0; j<4; j++) {
				if(t[j]==suppose[j]) s++;
				for(int k=0; k<4; k++) {
					if(k==j) continue;
					if(t[j]==suppose[k]) b++;
				}
			}
			if(s!=res.strike || b!=res.ball) noAns[i]=true;
		}
	}
}
