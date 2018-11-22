const int SIZE = 100;
const int MIN_RECT_SIZE = 10;
int myimage[SIZE+2][SIZE+2];
int layer[SIZE+2][SIZE+2];

struct Point {
    int x,y;
    Point(){}
    Point(int x, int y):x(x),y(y){}
    bool operator<(const Point &rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
};
template <class T>
struct Queue{
    T arr[20001];
    int f,r;
    Queue():f(0),r(0){}
    void init() {f=r=0;}
    void push(const T &x) { arr[r++]=x; }
    T pop() { return arr[f++]; }
    bool empty() const { return f>=r;}
    int size() const { return r-f; }
};
Queue<Point> q;
int recog(int image[SIZE][SIZE]) {
    q.init();
    for(register int i=0; i<SIZE+2; i++) {
        myimage[i][0]=myimage[0][i]=myimage[i][SIZE+1]=myimage[SIZE+1][i]=0;
        layer[i][0]=layer[0][i]=layer[i][SIZE+1]=layer[SIZE+1][i]=0;
    }
    for(register int i=0; i<SIZE; i++) {
        for(register int j=0; j<SIZE; j++) {
            myimage[i+1][j+1] = image[i][j];
        }
    }

    for(register int i=1; i<SIZE+2; i++) {
        for(register int j=1; j<SIZE+2; j++) {
            layer[i][j] = myimage[i][j]-myimage[i-1][j]-myimage[i][j-1]+myimage[i-1][j-1];
            if(layer[i][j]>0) q.push(Point(i,j));
        }
    }
    register int ans=0;
    while(!q.empty()) {
        Point p = q.pop();
        for(register int len = MIN_RECT_SIZE+1; p.x+len<SIZE+2 && p.y+len<SIZE+2; len++) {
            register int nx=p.x+len, ny=p.y+len;
            if(layer[nx][ny]>0 && layer[p.x][ny]<0 && layer[nx][p.y]<0) ans++;
        }
    }
    return ans;
}
