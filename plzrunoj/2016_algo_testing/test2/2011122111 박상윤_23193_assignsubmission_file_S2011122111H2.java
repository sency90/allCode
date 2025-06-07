import java.util.Scanner;
public class S2011122111H2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n= sc.nextInt();			//n�� �޾ƿ´�.
		int[] num =new int[n];			
		for(int i=0; i<n; i++){			//n���� ���� �޾ƿ�
			num[i]=sc.nextInt();
		}
		quicksort(num,0,num.length -1);	//������������ ����
		int result=0;					//����� ����
		int temp;						//������� �ɼ� �ִ��� Ȯ��
		for(int i=0;i<n;i++){			//index 0 ���� ���ǿ� �´��� �˻�
			if(num[i] < n-i) temp = num[i]; //������ ���� ��� ���ǿ� ����
			else temp = n-i;			
            		if(temp > result) result = temp; //���� ������� ũ�� ��� ����
    	}
		System.out.println(result);

	}
	static public void quicksort(int[] data, int l, int r){ //�� ��Ʈ ��������
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

