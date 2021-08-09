#include<stdio.h>
#include<string.h>
char s[100];
int top = -1;
void push(char x){
		top ++;
		s[top]=x;	
}
char pop(){
	char x = s[top];
	top--;
	return x;
}
char peak(){
	return s[top];
}
void display(){
	int i= top;
	while(i>=0){
		printf("%c",s[i]);
		i--;
	}
}

main(){
	char b;


	while(1){

		scanf("%c",&b);
		push(b);
		int ascii_c=b;
		if(ascii_c==120){
			display();
			return 0;
		}
	}
	
	
	
	
//	push('d');
//	push('r');
//	push('g');
//	display();
//	printf("\n");
	

}
