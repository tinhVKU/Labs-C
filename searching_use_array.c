#include<stdio.h>
int top =-1;
int dem=-1;
int s[100];
int nhap(int x){
	top++;
	s[top]=x;
	return x;
}
void find(int gt){
	int i;
	for(i=0;i<=top;i++){
		if(s[i]==gt){
			int dem=i+1;
			printf("So ban can tim o vi tri thu %d",dem);	
			return 0;
		}	
	}	
	if(dem==-1){
		printf("Khong tim thay!");
	}
}
int main(){
	int a;
	nhap(3);nhap(4);nhap(7);
	find(3);
}
