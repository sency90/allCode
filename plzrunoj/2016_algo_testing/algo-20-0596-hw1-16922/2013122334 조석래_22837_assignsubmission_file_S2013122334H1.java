package A;

import java.util.Scanner;

public class RG3 {
   private int[] preOrder;
   private int[] postOrder;
   private int root;
   private int scand_root = 0;
   private int index;
   private int[] inOrder;

   public RG3(int index, int[] preOrder,int[] postOrder){
      this.preOrder = preOrder;
      this.postOrder = postOrder;
      this.index = index;
      inOrder = new int[index+1];
      if(preOrder[0] == postOrder[index]){
         root = preOrder[0];
      }
      for(int i = 0; i <= index; i++){
    	  inOrder[i] = -1;
      }
   }
   public void Calculation(){
      scand_root = preOrder[1];
      int index_count = 0;
      int fex_index = 0;
      int find_index = 1;
      int add_index = 0;
      //int while_count = 0;
      
      int begin_index = 0;
      int end_index = 0;
      int order = 0;
      int scand_roop = 0;
      
      int the_end = -1;
      //while (while_count != 10){
    	 //while_count ++;
      while(the_end != 1){
    	 the_end = -1;
         while(true){
        	
        	
            if(scand_root == postOrder[index_count]){
               break;
            }
            else{
               index_count++;
            }
         }
         for(int k = 0; k < inOrder.length; k++){
 			if(inOrder[k] == -1){
 				the_end = 0;
 			}
 	     }
         if(the_end != 0){break;}
         if(postOrder[fex_index] == preOrder[find_index+1] && postOrder[fex_index+1] == preOrder[find_index+2] && postOrder[fex_index+2] == preOrder[find_index]){
        	begin_index = find_index;
            end_index = find_index + 2;
        	inOrder[add_index] = postOrder[fex_index];
            inOrder[add_index+1] = postOrder[fex_index+2];
            inOrder[add_index+2] = postOrder[fex_index+1];
            add_index += 2;
            
            fex_index += 2;
            find_index += 2;

            for(int k = 0; k < inOrder.length; k++){
    			if(inOrder[k] == -1){
    				the_end = 0;
    			}
    	    }
            System.out.println();
            if(add_index == index_count && the_end == 0){
               add_index += 1;
               fex_index += 1;
               find_index += 1;
               inOrder[add_index] = root;
               add_index++;
               root = -1;
               
            }

            else{
            	while(true){
            	//while(while_count != 20 && the_end == 0){
            		//while_count++;
            		if(add_index == index_count || add_index == index){
            			if(root != -1){
            				add_index++;
            				inOrder[add_index] = root;
            				root = -1;
            			}
            			add_index++;
            			order = 0;
            			break;
            		}
            		else{
            			if(order == 0 && begin_index > -1){
            				begin_index--;
            				add_index++;
            				inOrder[add_index] = preOrder[begin_index];
            				order = 1;
            			}
            			else if(end_index <= index_count){
            				end_index++;
            				add_index++;
            				inOrder[add_index] = preOrder[end_index];
            				order = 0;
            			}
            		}
            		for(int k = 0; k < inOrder.length; k++){
            			if(inOrder[k] == -1){
            				the_end = 0;
            			}
            	    }
            		if(the_end != 0){
            			break;
            		}
            	}
            }
            if(scand_roop == 0){
            	scand_root = preOrder[index_count + 2];
            	scand_roop = 1;
            }
            fex_index = index_count + 1;
         }
         else {
        	 //fex_index++;
        	 find_index++;
         }
         
      }
   }
   public int[] getInOrder(){
      return inOrder;
   }
   public static void main(String args[]){
      Scanner input = new Scanner(System.in);
      int index = 101;
      while(index > 1000){
    	  index = input.nextInt();
    	  if(index > 1000){System.out.print("재입력 : ");}
    	  
      }
      System.out.println("실행");
      int preOrder[] = new int[index];
      int postOrder[] = new int[index];
      //int index = 9;
      //int preOrder[] = {1,2,4,8,9,5,3,6,7};
      //int postOrder[] = {8,9,4,5,2,6,7,3,1};
      //int index = 7;
      //int preOrder[] = {1,2,4,5,3,6,7};
      //int postOrder[] = {4,5,2,6,7,3,1};
      
      for(int i = 0; i < preOrder.length; i++){
         preOrder[i] = input.nextInt();
      }
      for(int j = 0; j < preOrder.length; j++){
         postOrder[j] = input.nextInt();
      }
      RG3 g1 = new RG3((index-1), preOrder, postOrder);
      g1.Calculation();
      
      int[] inOrder = g1.getInOrder();
      for(int k = 0; k < inOrder.length; k++){
         System.out.print(inOrder[k]+" ");
      }
      
      
   }
}