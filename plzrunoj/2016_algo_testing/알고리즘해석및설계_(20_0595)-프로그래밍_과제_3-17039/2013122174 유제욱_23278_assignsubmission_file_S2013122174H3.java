import java.util.Scanner;

public class S2013122174H3 {
	Integer building[][][]=new Integer[100][100][100];

	
	public int find(int n, int l, int r) {
		if (building[n][l][r] != null)
			return building[n][l][r];
		else {
			if (l == 1 && r == 1) {
				if (n == 1)
					return 1;
				else 
					return 0;
			} 
			else if (l < 1 || r < 1 || l + r > n + 1)
				return 0;
			else{
				building[n][l][r]=(n - 2) * find(n - 1, l, r) + find(n - 1, l - 1, r) + find(n - 1, l, r - 1);
				return ((n - 2) * find(n - 1, l, r) + find(n - 1, l - 1, r) + find(n - 1, l, r - 1));
			}
		}
	}

	public static void main(String[] args) {

		int n, l, r,mod=1000000007;
		Scanner s = new Scanner(System.in);

		String num_s = s.nextLine();
		String[] temp = num_s.split(" ");
		n = Integer.parseInt(temp[0]);
		l = Integer.parseInt(temp[1]);
		r = Integer.parseInt(temp[2]);
		S2013122174H3 a = new S2013122174H3();
		System.out.println(a.find(n, l, r) % mod);
	}
}
