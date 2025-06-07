#include<iostream>
#include<cstdio>
using namespace std;
	
int *preorder; //���� ��ȸ �迭.
int *inorder; // ���� ��ȸ �迭.
int *postorder; // ���� ��ȸ �迭.
int pre_head; // ���� ��ȸ�� ��Ʈ ��� ����.
int post_head; // ���� ��ȸ�� ��Ʈ ��� ����.
int all_count;
int init(int count){ // ���� ���� ���� �ʱ�ȭ �Լ�.
	int i;
	all_count=count;
	preorder = new int[count];
	inorder = new int[count];
	postorder = new int[count];

	for(i=0;i<count;i++){ // 0���� �ʱ�ȭ.
		preorder[i]=0;
		inorder[i]=0;
		postorder[i]=0;
	}
	pre_head=0; //��ó�� ��Ʈ���� ���� �϶��� 0
	post_head=count-1; // �����϶��� ���������-1 �ΰ��� �ڸ���.

	return 0;
}
int print_inorder(){ //���� ��ȸ ����Լ�.
	int i;
	for(i=0;i<all_count;i++){
		printf("%d ",inorder[i]);
	}
	printf("\n");
	return 0;
}
int insert(int count,bool istrue){ // �����Լ�.
	int i,data;

	for(i=0;i<count;i++){
		scanf("%d",&data);
		if(istrue){ // ������ȸ �϶�.
			preorder[i]=data;
		}
		else{ //������ȸ �϶�.
			postorder[i]=data;
		}
	}

	return 0;
}
int search_head(int start,int end,int point){ // point: ã�� �����ġ.
	int i,line,j;
	int before_point;

	if(start>end){ // ������ȸ ���� �����÷ο� ���� ����.
		return 0;
	}
	if(end-start==2){ // ���� Ʈ�� ��尡 3���Ͻ�.
		if(postorder[start+1]==preorder[start+1] && preorder[start]<postorder[start]){ //�� ����Ʈ���� ������ ���.
			inorder[start]=postorder[end];
			inorder[end-1]=postorder[start];
			inorder[end]=postorder[start+1];
			return 0;
		}
		else if(postorder[start+1]==preorder[start+1] && preorder[start]>postorder[start]){ // �� ����Ʈ���� ������ ���. 
			inorder[end]=postorder[end];
			inorder[end-1]=postorder[start];
			inorder[start]=postorder[start+1];
			return 0;
		}
		else{ //����Ʈ���� �������� ������.
		inorder[end]=postorder[start+1];
		inorder[end-1]=postorder[end];
		inorder[start]=postorder[start];
		return 0;
		}
	}
	else if(end-start==1){ //����Ʈ�� ��尡 2���Ͻ�.
		inorder[start]=postorder[start];
		inorder[end]=postorder[end];
		return 0;
	}
	else if(end==start){ // ����Ʈ�� ��尡 1���Ͻ�.
		inorder[start]=postorder[start];
		return 0;
	}
	else{ //���� Ʈ�� ��尡 3���ʰ��Ͻ�.
		before_point=end; // �� ����� ����Ʈ.
		for(i=start;i<end;i++){// �� ����Ʈ���� 0���� �� ��� ����Ʈ���� ����Ʈ���� ��带 Ž��.
			if(preorder[point]==postorder[i]){ // ����Ʈ���� ��尡 Ž���ɰ��.
				end=i; // ���� ����Ʈ�� ����� ���� ����.
				inorder[end+1]=postorder[before_point]; //������ȸ ��忡 ã�� ���(��Ʈ���) ����.
				for(j=before_point;j>end+1;j--){ // ���Ե� ��Ʈ��带 ������ ��带 ���ġ.
					postorder[j]=postorder[j-1];
				}
				break;
			}
		}
		line=end-start+1; // ã�� ����� ��������,
		search_head(start,end,point+1); //���� ����Ʈ��.
		search_head(end+2,before_point,point+line); //���� ����Ʈ��.
	}
	return 0;
}

int main(){
	int node_count; // ��� ����, ��� ������ ��.
	scanf("%d",&node_count);
	init(node_count); //�޸� �Ҵ�.
	insert(node_count,true); //���� ��ȸ.
	insert(node_count,false); //���� ��ȸ.
	search_head(0,post_head,pre_head+1);
	print_inorder();

	delete preorder;
	delete inorder;
	delete postorder;
	return 0;
}