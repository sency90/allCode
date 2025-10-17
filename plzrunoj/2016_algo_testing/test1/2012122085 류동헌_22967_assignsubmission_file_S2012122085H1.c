#include<stdio.h>
#include <vector>

using namespace std;

static vector<int> LVR;		

vector<int> VLR_input(vector<int> VLR, int node_num);
void Print_Order(vector<int> something);
void Make_LVR(vector<int> VLR, vector<int> LRV, int node_num);
vector<int> LRV_input(vector<int> LRV, int node_num);

int main() {

	int node_num = 0;	
	vector<int> VLR_temp;
	vector<int> LRV_temp;
	
	scanf("%d", &node_num);

	if (node_num < 1 && node_num>1000) {
		printf("범위를 벗어났습니다.\n");
		return 0;
	}
	
	vector<int> VLR(VLR_input(VLR_temp, node_num));

	vector<int> LRV(LRV_input(LRV_temp, node_num));

	Make_LVR(VLR, LRV, node_num);

	Print_Order(LVR);
	return 0;
}



vector<int> VLR_input(vector<int> VLR, int node_num) {
	
	for (int i = 0; i < node_num; i++) {
		int temp = 0;
		scanf("%d", &temp);
		VLR.push_back(temp);
	}
	return VLR;
}

void Print_Order(vector<int> something) {
	for (int i = 0; i < something.size(); i++) {
		printf("%d ",something[i]);
	}
	printf("\n");
}

vector<int> LRV_input(vector<int> LRV, int node_num) {
	
	for (int i = 0; i < node_num; i++) {
		int temp = 0;
		scanf("%d", &temp);
		LRV.push_back(temp);
	}
	return LRV;
}

void Make_LVR(vector<int> VLR, vector<int> LRV, int node_num) {
	if (VLR.size() == 0) return;
	int root = VLR[0]; 
	int LRV_left_index = 0;	
	int LRV_left_num = 0;	

	vector<int> LRV_temp_left;			
	vector<int> LRV_temp_right;
	vector<int> VLR_temp_left;			
	vector<int> VLR_temp_right;

	if (node_num == 1) {				
		LVR.push_back(VLR[0]);
		return;
	}

	for (int i = 0; i < node_num; i++) {
		if (VLR[1] == LRV[i]) {
			LRV_left_index = i;				
			LRV_left_num = i + 1;			

			for (int j = 0; j < i + 1; j++) LRV_temp_left.push_back(LRV[j]);
			for (int j = i + 1; j < node_num-1; j++) LRV_temp_right.push_back(LRV[j]);
			for (int j = 1; j < i + 2; j++) VLR_temp_left.push_back(VLR[j]);
			for (int j = i + 2; j < node_num; j++) VLR_temp_right.push_back(VLR[j]);

			Make_LVR(VLR_temp_left, LRV_temp_left, i+1);
			LVR.push_back(root);
			Make_LVR(VLR_temp_right, LRV_temp_right, node_num - 2 - i);
		}
	}
}


