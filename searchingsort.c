#include<stdio.h>
int top=-1;
int s[100];
void nhap(int x){
	top++;
	s[top]=x;
}
findpossible(int gt){
	int f=-1;
	int l=0;
	int r=top;
	while(l<=r){
		int dem=(l+r)/2;
		if(gt>s[dem]){
		l= dem+1;
		}else if(gt<s[dem]){
			r = dem-1;
		}else{
			f= dem;
			printf("%d",f+1);
			break;
		}
	}
	return f;
}
int main(){
	//mang da dc sap xep
	nhap(2);nhap(3);nhap(4);nhap(5);nhap(6);nhap(9);
//	printf("%d",findpossible(3));
	findpossible(45);
}
