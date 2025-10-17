import java.util.*;
// 제출기한 : 2016년 12월 13일 오전 12시까지
public class S2015125034H2 {
	private Scanner scan = new Scanner(System.in);
	private int[] inputArray;
	private int ArraySize;
	
	public S2015125034H2(int Value) {
		this.inputArray = new int[Value];
		this.ArraySize = Value;
	}
	
	public void setArray() {
		String[] temp = new String[ArraySize];
		temp = scan.nextLine().split(" ");
		
		for (int i = 0; i < ArraySize; i++) {
			inputArray[i] = Integer.parseInt(temp[i]);
		}
	}
	
	public int getResult() {
		int X = -1;
		Arrays.sort(inputArray);
		for (int i = 0; i < ArraySize; i++) {
			if (inputArray[i] <= inputArray.length - i) {
				X = inputArray[i];
			}
		}
		return X;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		S2015125034H2 start = new S2015125034H2(size);
		start.setArray();
		int result = start.getResult();
		System.out.println(result);
		scan.close();
	}
}