#include<stdio.h>

int s[10];
int top = -1;
void push(int x){
		top ++;
		s[top]=x;	
}
int pop(){
	int x = s[top];
	top--;
	return x;
}
int peak(){
	return s[top];
}
void display(){
	int i= top;
	while(i>=0){
		printf("%d",s[i]);
		i--;
	}
}
void convert(int n){
	while(n!=0){
		int r = n%2;
		n=n/2;
		push(r);
	}
}
main(){
	push(1);
	push(2);
	push(3);
	display();
	printf("\n");
	top=-1;
	convert(1150256);
	display();

}
