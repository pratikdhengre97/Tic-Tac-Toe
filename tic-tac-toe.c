#include<stdio.h>
#include<conio.h>
void printTic();
int winner();
void system();

char values[] = { '0','1','2','3','4','5','6','7','8','9'};

void printTic() {
	system("cls");
	printf("\n\n");
    printf("    TIC TAC TOE         \n\n");
	
	printf("      |     |     \n");
	printf("   %c  |  %c  |  %c  \n",values[1],values[2],values[3]);
	printf(" _____|_____|_____\n");
	printf("      |     |     \n");
	printf("   %c  |  %c  |  %c  \n",values[4],values[5],values[6]);
	printf(" _____|_____|_____\n");
	printf("      |     |     \n");
	printf("   %c  |  %c  |  %c  \n",values[7],values[8],values[9]);
	printf("      |     |     \n\n");
}

int winner() {
	if(values[1]==values[2] && values[2]==values[3]) {
		return 1;
	}
	if(values[1]==values[4] && values[4]==values[7]) {
		return 1;
	}
	if(values[7]==values[8] && values[8]==values[9]) {
		return 1;
	}
	if(values[3]==values[6] && values[6]==values[9]) {
		return 1;
	}
	if(values[1]==values[5] && values[5]==values[9]) {
		return 1;
	}
	if(values[3]==values[5] && values[5]==values[7]) {
		return 1;
	}
	if(values[2]==values[5] && values[5]==values[8]) {
		return 1;
	}
	if(values[4]==values[5] && values[5]==values[6]) {
		return 1;
	}
	
    int count = 0;
    int i;
    for (i=1;i<=9;i++)
	{
		if(values[i]=='X' || values[i]=='O') {
			count++;
		}
	}
	
	if(count==9) {
		return 0;
	}	
	
	return -1;

}

void main () {
	
	
	int player = 1,input,status=-1;
	printTic();
	
	while(status==-1) {
		player=(player%2==0) ? 2 : 1;
		char target = (player==1) ? 'X' : 'O';
		printf("Enter the slot for player %d : ",player);
	    scanf("%d",&input);
	
	if(input<1 || input>9) {
		printf("Invalid input");
		
	}
	values[input]=target;
	printTic();
	
	int result=winner();
	
	if(result==1) {
		printf("Congratulations! Player %d is the Winner.",player);
		return 0;
	}
	else if(result==0) {
		printf("Draw");
		return 0;
	}
	player++;
	}
	
}
