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
void convert(int n){
	while(n!=0){
		int r = n%2;
		n=n/2;
		push(r);
	}
}
void display(){
	int i= top;
	while(i>=0){
		printf("%d",s[i]);
		i--;
	}
}
main(){
	int a;
	printf("---CHUONG TRINH HE THAP PHAN SANG HE NHI PHAN---\n\n");
	printf("Nhap so can chuyen: ");
	scanf("%d",&a)	;
	convert(a);
	printf("So nhi phan: ");
	display();

}
