import java.util.Scanner;
public class S2011122111H2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n= sc.nextInt();			//n값 받아온다.
		int[] num =new int[n];			
		for(int i=0; i<n; i++){			//n개의 값을 받아옴
			num[i]=sc.nextInt();
		}
		quicksort(num,0,num.length -1);	//오름차순으로 정렬
		int result=0;					//결과값 저장
		int temp;						//결과값이 될수 있는지 확인
		for(int i=0;i<n;i++){			//index 0 부터 조건에 맞는지 검사
			if(num[i] < n-i) temp = num[i]; //값보다 작은 경우 조건에 성립
			else temp = n-i;			
            		if(temp > result) result = temp; //이전 결과보다 크면 결과 갱신
    	}
		System.out.println(result);

	}
	static public void quicksort(int[] data, int l, int r){ //퀵 소트 오름차순
        int left = l;
        int right = r;
        int pivot = data[(l+r)/2];
        
        do{
            while(data[left] < pivot) left++;
            while(data[right] > pivot) right--;
            if(left <= right){    
                int temp = data[left];
                data[left] = data[right];
                data[right] = temp;
                left++;
                right--;
            }
        }while (left <= right);
        
        if(l < right) quicksort(data, l, right);
        if(r > left) quicksort(data, left, r);
    }	
	
}

