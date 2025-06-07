using namespace std;
#include <cstdio>
#include <iostream>
#define Num 1002





struct _tree
{
   
   int point;
   int p;
   int le;
   int ri;
};

struct _tree tree[Num];
int preorder[Num];
int postorder[Num];
int n;

void maketree(int num)
{
  
   int recent = preorder[num];
   int aa = 1; 
   tree[recent].point = 1;


  
   while (aa <= n && postorder[aa] != preorder[num + 1]){
      aa++;
	}

   if (aa > n){
      return;
	}

   
   if (tree[postorder[aa]].p == -1){
      tree[recent].le = postorder[aa];
      tree[postorder[aa]].p = recent;
   }

  
   while (aa <= n && postorder[aa] != preorder[num]){
   
      aa++;
   }

   if (aa > n){
      return;}

   
   if (tree[postorder[aa - 1]].p == -1){
      tree[recent].ri = postorder[aa - 1];
      tree[postorder[aa - 1]].p = recent;
   }

  
   for (int i = 1; i <= n; i++){
      if (preorder[i] == tree[recent].le)
         maketree(i);
   }

   
   for (int i = 1; i <= n; i++){
      if (preorder[i] == tree[recent].ri)
         maketree(i);
   }
}


void inorder(int recent){
   if (recent == -1 || tree[recent].point == -1){
      return;}

   inorder(tree[recent].le);

   printf("%d ", recent);

   inorder(tree[recent].ri);

}


int main(){
   int first;

  
   for (int i = 0; i < Num; i++){
      tree[i].point = -1;
      tree[i].ri = -1;
      tree[i].le = -1;
      tree[i].p = -1;
   }

   fill(preorder, preorder + Num, -1);
   fill(postorder, postorder + Num, -1);

   scanf("%d", &n);

   for (int i = 1; i <= n; i++){
      scanf("%d", &preorder[i]);}

   for (int i = 1; i <= n; i++){
      scanf("%d", &postorder[i]);}

   first = 1;
   maketree(first);
   inorder(preorder[1]);
   return 0;
}
