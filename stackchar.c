#include<stdio.h>
#include<string.h>
char s[100];
int top = -1;

void push(char x){
		top ++;
		s[top]=x;	
}
int pop(){
	char x = s[top];
	top--;
	return x;
}   
main(){
	char chuoi[100];
	printf("Nhap chuoi: ");
	gets(chuoi);
	int i ;
	for(i=0;i<strlen(chuoi);i++){
		push(chuoi[i]);
	}
	for(i=0;i<strlen(chuoi);i++){
		chuoi[i]=pop();
	}
	printf("%s",chuoi);
}
