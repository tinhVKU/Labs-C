    #include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>
struct list{
	char name[50];
	char date[20];
	float math;
	float physical;
	float language;
	struct list *next;
};
typedef struct list *node;

node creat(){
	char name[50];
	char date[20];
	float math;
	float physical;
	float language;

	printf("+ Ten: ");
	fflush(stdin);
	gets(name);
	printf("+ Ngay sinh: ");
	gets(date);
	printf("+ Toan: ");
	scanf("%f",&math);
	printf("+ Ly: ");
	scanf("%f",&physical);
	printf("+ Ngoai ngu: ");
	scanf("%f",&language);
	printf("\n");
	node tam;
	tam = (node)malloc(sizeof(struct list));
	tam->next = NULL;
	strcpy(tam->name,name);
	strcpy(tam->date,date);
	tam->math =math;
	tam->physical = physical;
	tam->language =language;
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

node delet(node dau,char *xoa){
	node run = dau;
	if(dau!=NULL){
		int dem=0;
	
		if(strcmp(run->name,xoa)==0){
			run = run->next;
		}else{
			while(run!=NULL){
			
				if(strcmp(run->next->name,xoa)==0){
					run->next= run->next->next;
					dem++;
					break;
				}
				run =run->next;
			}
			if(dem==0){
			printf("Nguoi nay khong co tronng danh sach\n");
			}
			return dau; 
		}
	}
	else{
		printf("Danh sach rong --> Khong the xoa\n");
	}

}

void findtoan(node dau){
	int gan=0;
	node run = dau;
	while(run!=NULL){
				
		if(run->math<5){
		
			printf("\nTen: ");
			puts(run->name);
			printf("Ngay Sinh: ");
			puts(run->date);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			printf("\tNgoai Ngu: %.2f \n",run->language);
			gan++; 
		} 
		
		run= run->next;
	}
	if(gan==0){
		printf("Khong co sinh vien nao\n") ;
	} 

}


void find(node dau,char *tim){
	int gan=0;
	node run = dau;
	printf("Tim kiem\n");
	while(run!=NULL){
				
		if(strcmp(run->name,tim)==0){
		
			printf("\nTen: ");
			puts(run->name);
			printf("Ngay Sinh: ");
			puts(run->date);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			printf("\tNgoai Ngu: %.2f \n",run->language);
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
			printf("Ngay Sinh: ");
			puts(run->date);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			printf("\tNgoai Ngu: %.2f \n",run->language);
			run = run->next;
		}
		printf("\n");
	}
	
}
void svmax(node dau,float max){
	node run = dau;
		while(run!=NULL){
				
		if((run->math+run->physical+run->language)/3==max){
		
			printf("\nTen: ");
			puts(run->name);
			printf("Ngay Sinh: ");
			puts(run->date);
			printf("Toan: %.2f ",run->math);
			printf("\tLy: %.2f ",run->physical);
			printf("\tNgoai Ngu: %.2f ",run->language);
			printf("\tDiem TB: %.2f\n",max);
		
		} 
		
		run= run->next;
	}
	
}
void sapxep(node dau,float *sum,int i){
	float max=sum[0];
	int j;
	for(j=1;j<=i;j++){
		if(sum[j]>max){
			max=sum[j];	
		}	
	}	
		svmax(dau,max);
}
void findmax(node dau){
	float sum[100];
	int i=0;
	node run = dau;
	while(run!=NULL){
		sum[i]= (run->math+run->physical+run->language)/3;	
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
	printf("\t\t\t!          5.Xoa                                   !\n");
	printf("\t\t\t!          6.Sinh vien co diem toan nho hon 5      !\n");
	printf("\t\t\t!          7.Sinh vien co diem TB cao nhat         !\n");
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
				printf("Nhap ten can xoa: ");
				fflush(stdin);
				gets(xoa);
				p=delet(p,xoa);
				 break;
			case 6:
				printf("Cac sinh vien co diem toan nho hon 5\n");
				findtoan(p);
				break;
			case 7:
				printf("Sinh vien co diem TB cao nhat\n");
				findmax(p);
				break;
			case 8:
				return 0;
			default: return 0;
		}
	}
}
