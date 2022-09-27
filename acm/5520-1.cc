#include <stdio.h>
#include <string.h>
using namespace std;
char button[9][8];
int button_len[9];
int clk_state_ans[9] = {0,0,0,0,0,0,0,0,0};
int clk_state[9];
int mn_ans_list[30], ans_list[30];
int mn_ans_len, ans_len;

void push(int button_no, int cnt) {
	if(cnt==0) return;
	int i, clk_no;
	for(i=0; i<button_len[button_no]; i++) {
		clk_no = button[button_no][i] -'A';
		clk_state[clk_no]+=cnt;
		if(clk_state[clk_no]>=4) clk_state[clk_no]-=4;
	}
	for(i=0; i<cnt; i++) {
		ans_list[ans_len++] = button_no+1;
	}
}
void unpush(int button_no, int cnt) {
	if(cnt==0) return;
	int i, clk_no;
	for(i=0; i<button_len[button_no]; i++) {
		clk_no = button[button_no][i] -'A';
		clk_state[clk_no]-=cnt;
		if(clk_state[clk_no]<0) clk_state[clk_no]+=4;
	}
	ans_len -= cnt;
}
void dfs(int x) {
	if(x==9) {
		if(memcmp(clk_state, clk_state_ans, sizeof(clk_state)) == 0) {
			if(mn_ans_len > ans_len) {
				mn_ans_len = ans_len;
				memcpy(mn_ans_list, ans_list, ans_len*sizeof(int));
			}
		}
		return;
	}
	int i;
	for(i=0; i<4; i++) {
		push(x, i);
		dfs(x+1);
		unpush(x, i);
	}
}
int main() {
	mn_ans_len = 0x3f3f3f3f;
	strcpy(button[0],"ABDE");
	strcpy(button[1],"ABC");
	strcpy(button[2],"BCEF");
	strcpy(button[3],"ADG");
	strcpy(button[4],"BDEFH");
	strcpy(button[5],"CFI");
	strcpy(button[6],"DEGH");
	strcpy(button[7],"GHI");
	strcpy(button[8],"EFHI");

	int i;
	for(i=0; i<9; i++) {
		button_len[i] = strlen(button[i]);
	}

	for(i=0; i<9; i++) {
		scanf("%d", &clk_state[i]);
	}
	dfs(0);

	for(i=0; i<mn_ans_len; i++) {
		printf("%d ", mn_ans_list[i]);
	}
	return 0;
}
