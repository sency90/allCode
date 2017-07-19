#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int v[301][301];
priority_queue<int> mxh;
priority_queue<int, vector<int>, greater<int> > mnh;
vector<int> g;
void print() {
    vector<int> tmp;
    while(!mxh.empty()) {
        tmp.push_back(mxh.top()); mxh.pop();
    }
    for(int i=tmp.size()-1; i>=0; i--) {
        printf("%d ", tmp[i]);
        mxh.push(tmp[i]);
    }
    printf("| ");
    tmp.clear();
    while(!mnh.empty()) {
        tmp.push_back(mnh.top()); mnh.pop();
    }
    for(int i=0; i<tmp.size(); i++) {
        printf("%d ", tmp[i]);
        mnh.push(tmp[i]);
    }
    puts("");
}
int main() {
    int r,c,h,w;
    scanf("%d%d%d%d",&r,&c,&h,&w);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            mxh.push(v[i][j]);
        }
    }
    int m=h*w/2+1;
    while(mxh.size()!=m) {
        mnh.push(mxh.top());
        mxh.pop();
    }
    int mn=mxh.top();
    while(!mxh.empty()) {
        mnh.push(mxh.top());
        mxh.pop();
    }
    for(int i=0; i<=r-h; i++) {
        if(i&1) {
            for(int j=c-1; j>=w; j--) {
                g.clear();
                for(int k=i; k<i+h; k++) {
                    g.push_back(v[k][j]);
                }
                sort(g.begin(), g.end());
                int idx=0;
                while(!mnh.empty() && idx<g.size()) {
                    if(g[idx]!=mnh.top()) {
                        mxh.push(mnh.top());
                        mnh.pop();
                    } else {
                        mnh.pop();
                        idx++;
                    }
                }

                if(mnh.empty()) mnh.push(mxh.top()), mxh.pop();
                int nj=j-w;
                for(int k=i; k<i+h; k++) {
                    if(v[k][nj]<mnh.top()) mxh.push(v[k][nj]);
                    else mnh.push(v[k][nj]);
                }
                if(mxh.size()>mnh.size()) {
                    while(mxh.size()!=m) {
                        mnh.push(mxh.top());
                        mxh.pop();
                    }
                    mn = min(mn, mxh.top());
                } else {
                    while(mnh.size()!=m) {
                        mxh.push(mnh.top());
                        mnh.pop();
                    }
                    mn = min(mn, mnh.top());
                }
                while(!mxh.empty()) {
                    mnh.push(mxh.top()); mxh.pop();
                }
            }
        } else {
            for(int j=0; j<c-w; j++) {
                g.clear();
                for(int k=i; k<i+h; k++) {
                    g.push_back(v[k][j]);
                }
                sort(g.begin(), g.end());
                int idx=0;

                while(!mnh.empty() && idx<g.size()) {
                    if(g[idx]!=mnh.top()) {
                        mxh.push(mnh.top());
                        mnh.pop();
                    } else {

                        mnh.pop();
                        idx++;
                    }
                }

                if(mnh.empty()) mnh.push(mxh.top()), mxh.pop();
                int nj=j+w;
                for(int k=i; k<i+h; k++) {
                    if(v[k][nj]<mnh.top()) mxh.push(v[k][nj]);
                    else mnh.push(v[k][nj]);
                }
                if(mxh.size()>mnh.size()) {
                    while(mxh.size()!=m) {
                        mnh.push(mxh.top());
                        mxh.pop();
                    }
                    mn = min(mn, mxh.top());
                } else {
                    while(mnh.size()!=m) {
                        mxh.push(mnh.top());
                        mnh.pop();
                    }
                    mn = min(mn, mnh.top());
                }
                while(!mxh.empty()) {
                    mnh.push(mxh.top()); mxh.pop();
                }
            }
        }

        if(i==r-h) break;
        while(!mxh.empty()) {
            mnh.push(mxh.top()); mxh.pop();
        }

        if(i&1) {
            g.clear();
            for(int j=0; j<w; j++) {
                g.push_back(v[i][j]);
            }
            sort(g.begin(), g.end());
            int idx=0;
            while(!mnh.empty() && idx<g.size()) {
                if(g[idx]!=mnh.top()) {
                    mxh.push(mnh.top());
                    mnh.pop();
                } else {
                    mnh.pop();
                    idx++;
                }
            }

            if(mnh.empty()) mnh.push(mxh.top()), mxh.pop();
            int ni=i+h;
            for(int j=0; j<w; j++) {
                if(v[ni][j]<mnh.top()) mxh.push(v[ni][j]);
                else mnh.push(v[ni][j]);
            }
            if(mxh.size()>mnh.size()) {
                while(mxh.size()!=m) {
                    mnh.push(mxh.top());
                    mxh.pop();
                }
                mn = min(mn, mxh.top());
            } else {
                while(mnh.size()!=m) {
                    mxh.push(mnh.top());
                    mnh.pop();
                }
                mn = min(mn, mnh.top());
            }
            while(!mxh.empty()) {
                mnh.push(mxh.top()); mxh.pop();
            }
        } else {
            g.clear();
            for(int j=c-w; j<c; j++) {
                g.push_back(v[i][j]);
            }
            sort(g.begin(), g.end());
            int idx=0;
            while(!mnh.empty() && idx<g.size()) {
                if(g[idx]!=mnh.top()) {
                    mxh.push(mnh.top());
                    mnh.pop();
                } else {
                    mnh.pop();
                    idx++;
                }
            }

            if(mnh.empty()) mnh.push(mxh.top()), mxh.pop();
            int ni=i+h;
            for(int j=c-w; j<c; j++) {
                if(v[ni][j]<mnh.top()) mxh.push(v[ni][j]);
                else mnh.push(v[ni][j]);
            }
            if(mxh.size()>mnh.size()) {
                while(mxh.size()!=m) {
                    mnh.push(mxh.top());
                    mxh.pop();
                }
                mn = min(mn, mxh.top());
            } else {
                while(mnh.size()!=m) {
                    mxh.push(mnh.top());
                    mnh.pop();
                }
                mn = min(mn, mnh.top());
            }
            while(!mxh.empty()) {
                mnh.push(mxh.top()); mxh.pop();
            }
        }
    }
    printf("%d\n", mn);
    return 0;
}
