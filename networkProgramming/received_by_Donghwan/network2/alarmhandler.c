#include<stdio.h>
#include<signal.h>

void alarm_handler(int);
void control_c_handler(int);

int beeps =0;


int main()
{
	//Assign signal handler
	signal(SIGALRM,alarm_handler);
	signal(SIGINT,control_c_handler);

	//alarm_handler later 1 minute
	alarm(1);

	while(1){
	}
}


void control_c_handler(int sig)
{
	return ;
}

void alarm_handler(int sig)
{
	printf("BEEP\n");
	

	if(++beeps<5)
		alarm(1);
	else
	{
		printf("End\n");
		exit(0);
	}
}


