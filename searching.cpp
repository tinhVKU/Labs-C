#include<stdio.h>
	int top =-1;
		int s[100];
int nhap(int x){
	top++;
	s[top]=x;
	return x;
}
int find(int gt){
	int i,dem=-1;
	for(i=0;i<top;i++){
		if(s[i]==gt){
			int dem=i;
			return dem;
		}	
		}	
	if(dem==-1){
		printf("Khong tim thay!");
	}
			
}
int main(){

	int a;
	printf("Nhap lan luot cac phan tu cua mang\n");
	nhap(3);nhap(4);
	find(2);
}
