import java.util.LinkedList; 
import java.util.Queue; 
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class S2008122007H1 {  
  
 	public Node makeBTree(int[] preOrder, int[] postOrder, int preStart, int preEnd, int index, int size) { 
 		if(preStart > preEnd || index > size-1) { 
 			Node node = new Node(); 
 			node.data = preOrder[index]; 
 			return node; 
 		} 
 		
 		Node node = new Node();
 		node.data = preOrder[index];
 
 		int i = 0; 
 		for(i = preStart; i <= preEnd; i++){ 
 			if(preOrder[index+1] == postOrder[i]){
 				break;
 				}
 			} 
 		
 		node.left = makeBTree(preOrder, postOrder, preStart, i-1, index+1, size); 
 		node.right = makeBTree(preOrder, postOrder, i+1, preEnd-1, index + i-preStart+2, size); 
 		return node; 
 	} 
 

 	public Node getpreOrderIndex(int[] preOrder, int[] postOrder, int size) { 
 		return makeBTree(preOrder, postOrder, 0, size-2, 0, size);
 	}  
 
 	public void printINORDER(Node root) { 
 		if(root != null) { 
 			printINORDER(root.left); 
 			System.out.print(" " + root.data); 
 			printINORDER(root.right); 
 		} 
 	} 
 
 
 	public static void main(String[] args) throws java.lang.Exception, IOException { 
 		 		 
 		 int[] preOrder = new int[1000]; 
 		 int[] postOrder = new int[1000];  
 		 int size;
 		
 		 Scanner put = new Scanner(System.in);
 		
 		 System.out.print("노드 수 입력 ");
 		 size = put.nextInt();
 		 		
 		 System.out.print("전위순회 입력 ");
 		 InputStreamReader r1 = new InputStreamReader(System.in);
         BufferedReader b1 = new BufferedReader(r1);
         String pre1 = b1.readLine();
         
         String[] slice1 = pre1.split(" ");
         
         for(int i = 0; i < size; i++){
              preOrder[i] = Integer.parseInt(slice1[i]);
             }
         
         
         System.out.print("후위순회 입력 ");
         InputStreamReader r2 = new InputStreamReader(System.in);
         BufferedReader b2 = new BufferedReader(r2);
         String pre2 = b2.readLine();
         
         String[] slice2 = pre2.split(" ");
         
         for(int i = 0; i < size; i++){
             postOrder[i] = Integer.parseInt(slice2[i]);
            }
 		
 		S2008122007H1 i = new S2008122007H1(); 
 		Node x = i.getpreOrderIndex(preOrder, postOrder, size); 
 		System.out.println("중위순회 결과 :"); 
 		i.printINORDER(x); 
 
 	} 
 } 

 
 class Node { 
 	int data; 
 	Node left; 
 	Node right; 
 
 	public Node() { 
 		this.data = data; 
 		left = null; 
 		right = null; 
 	} 
 } 

 
    // preOrder = { 1, 2, 4, 5, 3, 6, 7 }
	// postOrder = { 4, 5, 2, 6, 7, 3, 1 }
	// inOrder = { 4, 2, 5, 1, 6, 3, 7 }
 