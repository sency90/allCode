#include<iostream>
#include<cstdio>
using namespace std;
	
int *preorder; //전위 순회 배열.
int *inorder; // 중위 순회 배열.
int *postorder; // 후위 순회 배열.
int pre_head; // 전위 순회시 루트 헤드 번지.
int post_head; // 후위 순회시 루트 헤드 번지.
int all_count;
int init(int count){ // 전위 중위 후위 초기화 함수.
	int i;
	all_count=count;
	preorder = new int[count];
	inorder = new int[count];
	postorder = new int[count];

	for(i=0;i<count;i++){ // 0으로 초기화.
		preorder[i]=0;
		inorder[i]=0;
		postorder[i]=0;
	}
	pre_head=0; //맨처음 루트노드는 전위 일때는 0
	post_head=count-1; // 후위일때는 현재길이의-1 인것은 자명함.

	return 0;
}
int print_inorder(){ //중위 순회 출력함수.
	int i;
	for(i=0;i<all_count;i++){
		printf("%d ",inorder[i]);
	}
	printf("\n");
	return 0;
}
int insert(int count,bool istrue){ // 삽입함수.
	int i,data;

	for(i=0;i<count;i++){
		scanf("%d",&data);
		if(istrue){ // 전위순회 일때.
			preorder[i]=data;
		}
		else{ //후위순회 일때.
			postorder[i]=data;
		}
	}

	return 0;
}
int search_head(int start,int end,int point){ // point: 찾을 노드위치.
	int i,line,j;
	int before_point;

	if(start>end){ // 중위순회 스택 오버플로우 감지 조건.
		return 0;
	}
	if(end-start==2){ // 서브 트리 노드가 3개일시.
		if(postorder[start+1]==preorder[start+1] && preorder[start]<postorder[start]){ //우 편향트리를 포함한 경우.
			inorder[start]=postorder[end];
			inorder[end-1]=postorder[start];
			inorder[end]=postorder[start+1];
			return 0;
		}
		else if(postorder[start+1]==preorder[start+1] && preorder[start]>postorder[start]){ // 좌 편향트리를 포함한 경우. 
			inorder[end]=postorder[end];
			inorder[end-1]=postorder[start];
			inorder[start]=postorder[start+1];
			return 0;
		}
		else{ //편향트리를 포함하지 않을시.
		inorder[end]=postorder[start+1];
		inorder[end-1]=postorder[end];
		inorder[start]=postorder[start];
		return 0;
		}
	}
	else if(end-start==1){ //서브트리 노드가 2개일시.
		inorder[start]=postorder[start];
		inorder[end]=postorder[end];
		return 0;
	}
	else if(end==start){ // 서브트리 노드가 1개일시.
		inorder[start]=postorder[start];
		return 0;
	}
	else{ //서브 트리 노드가 3개초과일시.
		before_point=end; // 전 노드의 포인트.
		for(i=start;i<end;i++){// 좌 서브트리는 0부터 전 노드 포인트까지 서브트리의 노드를 탐색.
			if(preorder[point]==postorder[i]){ // 서브트리의 노드가 탐색될경우.
				end=i; // 다음 서브트리 노드의 끝을 지정.
				inorder[end+1]=postorder[before_point]; //중위순회 노드에 찾은 노드(루트노드) 삽입.
				for(j=before_point;j>end+1;j--){ // 삽입된 루트노드를 제외한 노드를 재배치.
					postorder[j]=postorder[j-1];
				}
				break;
			}
		}
		line=end-start+1; // 찾은 노드의 개수개산,
		search_head(start,end,point+1); //좌측 서브트리.
		search_head(end+2,before_point,point+line); //우측 서브트리.
	}
	return 0;
}

int main(){
	int node_count; // 노드 갯수, 노드 데이터 값.
	scanf("%d",&node_count);
	init(node_count); //메모리 할당.
	insert(node_count,true); //전위 순회.
	insert(node_count,false); //후위 순회.
	search_head(0,post_head,pre_head+1);
	print_inorder();

	delete preorder;
	delete inorder;
	delete postorder;
	return 0;
}