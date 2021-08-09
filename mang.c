#include<stdio.h>
void nhap(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("Nhap phan tu a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("Phan tu a[%d]: %d\n",i,a[i]);
	}
}
void them(int a[],int *n,int x){
	*n=*n+1;
	a[*n-1]=x;
}
void Delete(int a[], int n, int ViTriXoa){
	int i;
	for(i = ViTriXoa; i < n; i++){
		a[i] = a[i + 1];
		}	
		n--;	
}
void xoasole(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i]%2!=0){
		
		Delete(a,n,i);
		i--;
	}
}
}
int main(){
	printf("\t---Mang---\n");
	int n,sl,i,x;
	printf("Nhap vao so luong phan tu cua mang\n");
	scanf("%d",&n);
	int a[n];
	nhap(a,n);
	xuat(a,n);
	printf("Nhap so luong phan tu can them \n");
	scanf("%d",&sl);
	for(i=1;i<=sl;i++){
		printf("Nhap so can them: \n");
		scanf("%d",&x);
		them(a,&n,x);
	}
	xuat(a,n);
	printf("====================\n");
	xoasole(a,n);
	xuat(a,n);
}
