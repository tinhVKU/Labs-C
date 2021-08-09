#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct SinhVien{
    char ten[30];
    char classroom[5];
   
    float dL, dH;
   
}b;
typedef SinhVien ,SV;
void nhap(SV sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
int main(){
	int n;
   printf("---Chuong trinh quan li sinh vien---\n");
   printf("\nNhap vao so luong sinh vien: ");
   scanf("%d",&n);
   SV a[n];
   nhapN(a,n);
   xuatN(a,n);
   }
void nhap(SV sv){
    printf("\nNhap ten: "); fflush(stdin); gets(b.ten);
    printf("\nNhap phong: "); gets(b.classroom);
    printf("\nNhap diem li: "); scanf("%f", &b.dL);
    printf("\nNhap diem hoa: "); scanf("%f", &b.dH);
}
 
void nhapN(SV a[], int n){
	int i;
    for( i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:\n", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void xuat(SV sv){
    printf("\tHo ten SV: %s", b.ten);
    printf("\tPhong: %s", b.classroom);
    printf("\tDiem Ly: %.2f", b.dL);
    printf("\tDiem Hoa: %.2f\n", b.dH);
}
 
void xuatN(SV a[], int n){
	int i;
    for( i = 0;i < n;++i){
        printf("\nThong tin SV thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}

