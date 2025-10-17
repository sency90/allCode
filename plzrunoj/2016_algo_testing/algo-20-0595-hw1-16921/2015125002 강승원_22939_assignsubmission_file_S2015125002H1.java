import java.util.*;

public class S2015125002H1 {
	static int[] front;
	static int[] back;

	public static void func(int start, int end) {
		System.out.println("good");
		if(start==end) return;
		int root = front[start];
		int next_root = front[start + 1];
		int i;
		for (i = start; i < end; i++)
			if (back[i] == next_root)
				break;

		for (int j = start; j < i + 1; j++)
			front[j] = front[j + 1];
		for (int j = end; j > i + 1; j--)
			back[j] = back[j - 1];
		front[i + 1] = root;
		back[i + 1] = root;
		func(start, i);
		func(i + 2, end);
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int len = s.nextInt();
		s.nextLine();
		String front_str = s.nextLine();
		String back_str = s.nextLine();
		String[] temp;

		front = new int[len];
		back = new int[len];
		temp = front_str.split(" ");
		for (int i = 0; i < len; i++)
			front[i] = (Integer.parseInt(temp[i]));

		temp = back_str.split(" ");
		for (int i = 0; i < len; i++)
			back[i] = (Integer.parseInt(temp[i]));
		func(0, len - 1);

		for (int i = 0; i < len; i++) {
			if(i==len-1) {
				System.out.printf("%d", back[i]);
				return;
			}
			System.out.printf("%d ", back[i]);
		}
		return;
	}
}
