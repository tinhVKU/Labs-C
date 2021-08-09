#include<stdio.h>
int array[100];
int top =-1;
void input(int x){
	top++;
	array[top]=x;
}
void output(){
	int i ;
	printf("Cac phan tu trong mang: \n");
	for(i=0;i<=top;i++){
		printf("array[%d] = %d\n",i,array[i]);
	}
}
int searchLinear(int gt){
	int f=-1;
	int i;
	for(i=0;i<=top;i++){
		if(array[i]==gt){
			f=i+1;
			printf("So ban dang tim o vi tri: array[%d]\n",i);
			return f;
		}
	}
	if(f==-1){
		printf("Khong tim thay!\n");
	}
}
void sort(){
	int i,h,j;
	for(i=0;i<=top;i++){
		for(j=i+1;j<=top;j++){
			if(array[i]>array[j]){
				int tam = array[i];
				array[i]= array[j];
				array[j]=tam;
			}
		}
	}
	printf("Mang sau khi sap xep la: \n");
	for(h=0;h<=top;h++){
		printf("array[%d] = %d\n",h,array[h]);
	}
}
void searchBin(int gt){
	int f=-1;
	int l=0;
	int r=top;
	while(l<=r){
		int dem=(l+r)/2;
		if(gt>array[dem]){
		l= dem+1;
		}else if(gt<array[dem]){
			r = dem-1;
		}else{
			f= dem;
			printf("So ban dang tim o vi tri: array[%d]\n",f);
			break;
		}
	}
	if(f==-1){
		printf("Khong tim thay!\n");
	}
	return f;
}
int main(){
	int n,i,x,gt,tim;
	printf("--Chuong trinh quan li so nguyen--\n");
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	printf("Nhap lan luot cac so: \n");
	for(i=1;i<=n;i++){
		printf("array[%d]: ",i-1);
		scanf("%d",&x);
		input(x);
	}
	output();
	printf("Nhap gia tri can tim: ");
	scanf("%d",&gt);
	searchLinear(gt);sort();
	printf("Nhap gia tri can tim: ");
	scanf("%d",&tim);
	searchBin(tim);
}
