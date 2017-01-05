import java.util.Scanner;

public class S2015125041H3 {
	public static int L;
	public static int R;
	public static int cnt=0;
	
	public static void Permute(int[] input, int startindex) {
        int size = input.length;
        int tmp_l;
        int tmp_r;
        int[] tmp = new int[size];
        if(size == startindex + 1) {
            for(int i = 0; i < size; i++) {
                tmp[i] = input[i];                
            }
            tmp_l = 1;
            tmp_r = 1;
            for(int i = 0; i < size-1; i++) {
            	if(tmp[i]<tmp[i+1])
            		tmp_l++;
            	else
            		break;
            }
            if(tmp_l == L){
            	for(int i = size-1; i > 0; i--) {
                	if(tmp[i-1]>tmp[i])
                		tmp_r++;
                	else
                		break;
                }
            	if(tmp_r == R)
            		cnt++;
            }
        }else{
            for(int i = startindex; i < size; i++) {
                int temp = input[i];
                input[i] = input[startindex];
                input[startindex] = temp;
                Permute(input, startindex + 1);
                temp = input[i];
                input[i] = input[startindex];
                input[startindex] = temp;
            }
        }
    }

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] tmp = sc.nextLine().split(" ");
		int N;
		L = Integer.parseInt(tmp[1]);
		R = Integer.parseInt(tmp[2]);
		Scanner in = new Scanner(System.in);
        N = Integer.parseInt(tmp[0]);
        int[] arr = new int[N];
        for(int i = 1; i <= N; i++) {
            arr[i-1] = i;
        }
        Permute(arr, 0);
        System.out.println(cnt%1000000007);
	}
}
