#include<stdio.h>
int main(){
	int a,b;
	printf("Nhap lan luot 2 so: \n");
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	if(a>b){
		printf("So lon nhat la: %d",a);
	}
	else{
		printf("So lon nhat la: %d",b);
	}
}
