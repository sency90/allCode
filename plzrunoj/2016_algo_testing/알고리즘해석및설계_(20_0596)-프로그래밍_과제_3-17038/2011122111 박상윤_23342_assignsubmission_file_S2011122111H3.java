import java.util.Scanner;

public class S2011122111H3 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		int R = sc.nextInt();
		
		double[][][] dist = new double[N+1][L+1][R+1];
		
		dist[0][0][1] = 1;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= L; j++) {
				for (int k = 1; k <= R; k++) {
					dist[i][j][k] += (dist[i-1][j-1][k] % 1000000007);
					dist[i][j][k] += (dist[i-1][j][k-1] % 1000000007);
					if (i >= 2) {
						dist[i][j][k] += ((i-2)*dist[i-1][j][k]%1000000007); 
					}
				}
			}
		}
		
		System.out.println(dist[N][L][R]%1000000007);
		
	}
}
