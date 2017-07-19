#include<iostream>
using namespace std;
int main(){
    int month,num,cur,n;
    double d, o, value, debe, porc, use, r[150];
    while(1){
        cin>>month>>d>>o>>num;
        if(month<0) break;
        fill(r,r+150,-1.0);
        for(int i=0;i<num;i++){
            cin>>n>>porc;
            r[n]=porc;
        }
        for(int i=1;i<150;i++) if(r[i]==-1.0) r[i]=r[i-1];
        use=o/month;
        value=o+d;
        debe=o;
        cur=0;
        while(1){
            value*=(1-r[cur]);
            if(debe<value){
                cout<<cur;
                if(cur==1) cout<<" month"<<endl;
                else cout<<" months"<<endl;
                break;
            }
            debe-=use;
            cur++;
        }
    }
    return 0;
}
