    #include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>
struct list{
	char name[30];
	char lop[10];
	float math;
	float physical;
	float avg;
	struct list *next;
};
typedef struct list *node;

node creat(){
	char name[30];
	char lop[10];
	float math;
	float physical;
//	float avg;

	printf("+ Ten: ");
	fflush(stdin);
	gets(name);
	printf("+ Lop: ");
	gets(lop);
	printf("+ Toan: ");
	scanf("%f",&math);
	printf("+ Ly: ");
	scanf("%f",&physical);

	
	printf("\n");
	node tam;
	tam = (node)malloc(sizeof(struct list));
	tam->next = NULL;
	strcpy(tam->name,name);
	strcpy(tam->lop,lop);
	tam->math =math;
	tam->physical = physical;
	tam->avg=(tam->math+tam->physical)/2;
	return tam;  
}
node nhap(node dau){
	node tam = creat();
	 if(dau==NULL){
	   	dau=tam;
	   }
	else{
		node run = dau;
	   	while(run->next!=NULL){
	   		run = run->next;
		   }
		   	run->next=tam;
	   }
	  return dau;	
}
void find(node dau,char *tim){
	int gan=0;
	node run = dau;
	printf("Tim kiem\n");
	while(run!=NULL){
				
		if(strcmp(run->name,tim)==0){
		
			printf("\nTen: ");
			puts(run->name);
			printf("Lop: ");
			puts(run->lop);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			printf("\tDiem TB: %.2f \n",run->avg);
			gan++; 
		} 
		
		run= run->next;
	}
	if(gan==0){
		printf("Khong tim thay\n") ;
	} 

}
void xuat(node dau){
	node run = dau;
	if(run!= NULL){
		printf("\tThong tin sinh vien\n");
		while(run!=NULL){
			printf("\nTen: ");
			puts(run->name);
			printf("Lop: ");
			puts(run->lop);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			
			printf("\tDiem TB: %.2f \n",run->avg);
			run = run->next;
		}
		printf("\n");
	}
	
}
void sapxep(node dau,float *sum,int i){
	int j,h,g;
	for(j=0;j<i;j++){
		for(h=j+1;h<i;h++){
			if(sum[j]<sum[h]){
				float tam = sum[j];
				sum[j]= sum[h];
				sum[h]=tam;
			}
		}
	}

	for(g=0;g<i;g++){
			node run = dau;
		
		while(run!=NULL){
		if(run->avg==sum[g]){
		
			printf("\nTen: ");
			puts(run->name);
			printf("Lop: ");
			puts(run->lop);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			printf("\tDiem TB: %.2f \n",run->avg);
			dau= dau->next;
			}
		run= run->next;
		}
	}
	
}
void max(node dau){
	float sum[100];
	int i=0;
	node run = dau;
	while(run!=NULL){
		sum[i]= run->avg;	
		i++;
		run= run->next;
	}
	sapxep(dau,sum,i);
}
void print(){
	printf("\t\t\t========DANH SACH LIEN KET========\n\n");
	printf("\t\t\tCac chuc nang chinh cua chuong trinh\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\t\t\t!          1.Nhap thong tin sinh vien              !\n");
	printf("\t\t\t!          2.Xuat ra man hinh                      !\n");
	printf("\t\t\t!          3.Them sinh vien                        !\n");
	printf("\t\t\t!          4.Tim theo ten                          !\n");
	printf("\t\t\t!          5.Sap xep theo diem TB                  !\n");
	printf("\t\t\t!          8.Thoat chuong trinh                    !\n");
	printf("\t\t\t----------------------------------------------------\n");
}
int main(){
		char tim[50];
		char xoa[50];
	node p = (node)malloc(sizeof(struct list));
	p = NULL;
	int sl,chon,ad;
//	int chon,gt,ad,vt,so,a,tim;
	print();
	while(1){
		printf("Nhap chuc nang: ");
		scanf("%d",&chon);
		printf("\t----------------------------------\n");
		switch(chon){
			case 1:
				printf("Nhap so luong sinh vien: ");
				scanf("%d", &sl);
				if(sl==1){
					p =nhap(p);
				}else{
					int i;
				for(i=1;i<=sl;i++){
					printf("\t-Thong tin sinh vien thu: %d\n",i);
					 p= nhap(p);
				}	
				}
				break;
			case 2:
				xuat(p);
				break;
			case 3:
				printf("Nhap so can them: ");
				scanf("%d", &ad);
				if(ad==1){
					p =nhap(p);
				}
				else{
					int j;
				for(j=1;j<=ad;j++){
					printf("\t-Thong tin sinh vien thu: %d\n",j);
					 p= nhap(p);
				}	
				}
				break;
			case 4:
				printf("Nhap ten muon tim: ");
				fflush(stdin);
				gets(tim);
				find(p,tim);
				break;
			case 5:
				max(p);
				break;
			case 8:
				return 0;
			default: return 0;
		}
	}
}
