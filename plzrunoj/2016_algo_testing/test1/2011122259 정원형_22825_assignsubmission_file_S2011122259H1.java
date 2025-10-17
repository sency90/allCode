import java.util.Scanner;
import java.util.Arrays;

public class S2011122259H1 {
	public static void main(String args[]) {
		final int MAXSIZE = 1000;
		int[] preorder = new int[MAXSIZE]; // 전위순회
		int[] postorder = new int[MAXSIZE]; // 후위순회
		int[] inorder = new int[MAXSIZE]; // 중위순회
		int tree_size = 0;
		Scanner in = new Scanner(System.in);

		// 트리 사이즈 입력
		tree_size = in.nextInt();

		// 전위순회 입력
		for (int i = 0; i < tree_size; i++) {
			preorder[i] = in.nextInt();
		}

		// 후위순회 입력
		for (int i = 0; i < tree_size; i++) {
			postorder[i] = in.nextInt();
		}

		// 중위순회
		Inorder inor = new Inorder();
		inorder = inor.makeTree(preorder, postorder, tree_size, inorder, 0);

		//결과값 출력
		for (int i = 0; i < tree_size; i++) {
			System.out.print(inorder[i] + " ");
		}
	}
	
	 static class Inorder {
		public int[] makeTree(int[] pre, int[] post, int index,int[] tree, int cor){
			int rightstart;	// 전위순회 기준 right Child의 시작 인덱스
			int rightend;	// 		"					"				끝 인덱스
			int leftstart;	// 후위순회 기준 left Child의 시작 인덱스
			int leftend;	// 		"					"				끝 인덱스
			int rootnum;	// 루트에 들어갈 값
			
			if(index==1){	// 자식노드가 없을경우
				tree[cor] = pre[0];
				return null;
			}
			if(index == 2){	// 자식노드가 하나일 경우
				tree[cor+1] = pre[0];
				tree[cor] = pre[1];
				return null;
			}
			rootnum = pre[0];		//root값
			
			rightstart = findnum(pre,index,post[index-2]);
					//rightChild의 첫번째 인덱스:후위순회의 index번째 값과 같은값이 있는 전위순회의 인덱스
			rightend = index-1;	//rightChild의 끝인덱스	전위순회
			
			leftstart = 0;			// leftChild의 첫번째 인덱스  후위순회
			leftend = findnum(post, index, pre[1]);
					//leftChild의 마지막 인덱스 : 전위순회 2번째 값과 같은값이 있는 후위순회의 인덱스
			tree[leftend+1+cor] =rootnum;
				//leftChild
				makeTree(Arrays.copyOfRange(pre, 1, rightstart),Arrays.copyOfRange(post, leftstart, leftend+1),leftend-leftstart+1,tree,cor);
				//rightChild
				makeTree(Arrays.copyOfRange(pre, rightstart, rightend+1),Arrays.copyOfRange(post, leftend+1, index-1),rightend-rightstart+1,tree,leftend+cor+2);
				
			return tree;
		}
		
		public int findnum(int[] arr, int end, int num){
				//배열에 num과 같은 값인지 검사하는 함수.
			for(int i= 0; i<end; i ++){
				if(num == arr[i]){
					return i;
				}
			}
			return -1;	//  에러
		}
	}

}
