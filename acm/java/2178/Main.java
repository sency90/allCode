import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N, M, ad[][];
		boolean visit[][];
		Scanner sc = new Scanner(System.in);
		String matrix = "";
		N = sc.nextInt();
		M = sc.nextInt();

		ad = new int[N][M];
		visit = new boolean[N][M];

		for (int i = 0; i < N; i++) {
			matrix = sc.next();
			for (int j = 0; j < M; j++) {
				ad[i][j] = Integer.parseInt(matrix.charAt(j) + "");
				visit[i][j] = false;
			}
		}

		BFS(ad,visit,N,M);
		sc.close();
	}

	public static void BFS(int ad[][],boolean visit[][],int N,int M)  {
		Queue<Point> q = new LinkedList<Point>();
		int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
		Point p = new Point(0,0);
		int ans = 1;

		q.add(p);
		visit[0][0] = true;
		while (!q.isEmpty()) {
			int sz = q.size();
			for (int z = 0; z < sz; z++) {
				p = q.poll();
				int x = p.x, y = p.y;
                if (x == N - 1 && y ==M - 1) {
                    System.out.println(ans);
                    while(!q.isEmpty()) q.poll();
                    break;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if(ad[nx][ny]==0 || visit[nx][ny]) continue;

                    visit[nx][ny] = true;
                    q.add(new Point(nx,ny));
                }
            }
            ++ans;
        }
    }
}

class Point {
    int x, y; // x,y,l que 맵핑
    public Point(int x, int y) {
        super();
        this.x=x;
        this.y=y;
    }
}
