import java.util.Scanner;
import java.util.Arrays;

public class S2011122259H1 {
	public static void main(String args[]) {
		final int MAXSIZE = 1000;
		int[] preorder = new int[MAXSIZE]; // ������ȸ
		int[] postorder = new int[MAXSIZE]; // ������ȸ
		int[] inorder = new int[MAXSIZE]; // ������ȸ
		int tree_size = 0;
		Scanner in = new Scanner(System.in);

		// Ʈ�� ������ �Է�
		tree_size = in.nextInt();

		// ������ȸ �Է�
		for (int i = 0; i < tree_size; i++) {
			preorder[i] = in.nextInt();
		}

		// ������ȸ �Է�
		for (int i = 0; i < tree_size; i++) {
			postorder[i] = in.nextInt();
		}

		// ������ȸ
		Inorder inor = new Inorder();
		inorder = inor.makeTree(preorder, postorder, tree_size, inorder, 0);

		//����� ���
		for (int i = 0; i < tree_size; i++) {
			System.out.print(inorder[i] + " ");
		}
	}
	
	 static class Inorder {
		public int[] makeTree(int[] pre, int[] post, int index,int[] tree, int cor){
			int rightstart;	// ������ȸ ���� right Child�� ���� �ε���
			int rightend;	// 		"					"				�� �ε���
			int leftstart;	// ������ȸ ���� left Child�� ���� �ε���
			int leftend;	// 		"					"				�� �ε���
			int rootnum;	// ��Ʈ�� �� ��
			
			if(index==1){	// �ڽĳ�尡 �������
				tree[cor] = pre[0];
				return null;
			}
			if(index == 2){	// �ڽĳ�尡 �ϳ��� ���
				tree[cor+1] = pre[0];
				tree[cor] = pre[1];
				return null;
			}
			rootnum = pre[0];		//root��
			
			rightstart = findnum(pre,index,post[index-2]);
					//rightChild�� ù��° �ε���:������ȸ�� index��° ���� �������� �ִ� ������ȸ�� �ε���
			rightend = index-1;	//rightChild�� ���ε���	������ȸ
			
			leftstart = 0;			// leftChild�� ù��° �ε���  ������ȸ
			leftend = findnum(post, index, pre[1]);
					//leftChild�� ������ �ε��� : ������ȸ 2��° ���� �������� �ִ� ������ȸ�� �ε���
			tree[leftend+1+cor] =rootnum;
				//leftChild
				makeTree(Arrays.copyOfRange(pre, 1, rightstart),Arrays.copyOfRange(post, leftstart, leftend+1),leftend-leftstart+1,tree,cor);
				//rightChild
				makeTree(Arrays.copyOfRange(pre, rightstart, rightend+1),Arrays.copyOfRange(post, leftend+1, index-1),rightend-rightstart+1,tree,leftend+cor+2);
				
			return tree;
		}
		
		public int findnum(int[] arr, int end, int num){
				//�迭�� num�� ���� ������ �˻��ϴ� �Լ�.
			for(int i= 0; i<end; i ++){
				if(num == arr[i]){
					return i;
				}
			}
			return -1;	//  ����
		}
	}

}
