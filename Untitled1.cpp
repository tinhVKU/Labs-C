#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct list{
	char name[50];
	char date[20];
	float math;
	float physical;
	float language;
	struct list *next;
};
typedef struct list *node;
node tao(char ten[],char nsinh[],float toan,float ly,float avan){
	node tam;
	tam = (node)malloc(sizeof(struct list));
	tam->next = NULL;
	*tam->name = ten[50];
	*tam->date =nsinh[20];
	tam->math =toan;
	tam->physical = ly;
	tam->language =avan;
	return tam;
}
void nhap(){
	char name[50];
	char date[20];
	float math;
	float physical;
	float language;
	printf("Ten: ");
	fflush(stdin);
	gets(name);
	printf("Ngay sinh: ");
	gets(date);
	printf("Toan: ");
	scanf("%f",&math);
	printf("Ly: ");
	scanf("%f",&physical);
	printf("Ngoai ngu: ");
	scanf("%f",&language);
	tao(name,date,math,physical,language);
}

//node nhap(node dau,int gt){
//	   node tam = tao(gt);
//	   if(dau==NULL){
//	   	dau=tam;
//	   }
//	   else{
//	   	tam->next = dau;
//	   	dau = tam;
//	   }
//	   return dau;
//}
//node addduoi(node dau,int ad){
//	node tam = tao(ad);
//	 if(dau==NULL){
//	   	dau=tam;
//	   }
//	else{
//		node run = dau;
//	   	while(run->next!=NULL){
//	   		run = run->next;
//		   }
//		   	run->next=tam;
//	   }
//	  return dau;	
//}
//node addvt(node dau,int a,int so){
//	int dem=0;
//	node tam = tao(so);
//	node run = dau;
//	if(a==1){
//		adddau(run,so);
//	}
//	else{
//			while(run!=NULL){
//			
//				run = run->next;
//					dem++;
//			}
//			if(dem<a){
//				addduoi(dau,so);
//			}
//			else {
//				node run =dau;
//				int i;
//				for(i=1;i<a-1;i++){
//					run = run->next;
//				}
//			 	tam->next = run->next;
//			  	run->next=tam;
//			  return dau;
//			}
//	}
//}
//node xoa(node dau,int vt){
//
//	if(dau!=NULL){
//			int dem=0;
//	node run = dau;
//	if(vt==1){
//		dau= dau->next;
//			return dau;
//	}
//	else{
//			while(run!=NULL){
//			
//				run = run->next;
//					dem++;
//			}
//			if(dem<vt){
//				node run = dau;
//				while(run->next->next!= NULL){
//				run = run->next;
//				}
//				run->next=NULL;
//				return dau;
//			}
//			else {
//				node run =dau;
//				int i;
//				for(i=1;i<vt-1;i++){
//					run = run->next;
//				}
//			 	run= run->next->next;
//			  return dau;
//			}
//	}
//	
//		}
//
//}
//void find(node dau,int tim){
//	int dem,gan=0;
//	node run = dau;
//	while(run!=NULL){
//		
//		if(run->data==tim){
//			printf("So ban can tim dang o vi tri thu: %d\n",dem+1);	
//			gan++; 
//		} 
//		dem++;
//		run= run->next;
//	}
//	if(gan==0){
//		printf("Khong tim thay\n") ;
//	} 
//
//}
void xuat(node dau){
	node run = dau;
	if(run!= NULL){
//		printf("%d ",run->data);
		while(run!=NULL){
			printf("%s ",run->name);
			printf("%s ",run->date);
			printf("%f ",run->math);
			printf("%f ",run->physical);
			printf("%f ",run->language);
			run = run->next;
		}
		printf("\n");
	}
	
}
void print(){
	printf("\t========DANH SACH LIEN KET========\n\n");
	printf("Cac chuc nang chinh cua chuong trinh\n");
	printf("--------------------------------------\n");
	printf("!       1.Nhap thong tin sinh vien   !\n");
	printf("!       2.Xuat ra man hinh           !\n");
	printf("!       3.Them so vao duoi     	     !\n");
	printf("!       4.Them so vao vi tri   	     !\n");
	printf("!       5.Xoa               	     !\n");
	printf("!       6.Tim               	     !\n");
	printf("!       7.Thoat chuong trinh         !\n");
	printf("--------------------------------------\n");
}
int main(){
	
	node p = (node)malloc(sizeof(struct list));
	p = NULL;
	int sl,chon;
//	int chon,gt,ad,vt,so,a,tim;
	print();
	while(1){
		printf("Nhap chuc nang: ");
		scanf("%d",&chon);
		switch(chon){
			case 1:
				printf("Nhap so luong sinh vien: ");
				scanf("%d", &sl);
				int i;
				for(i=1;i<=sl;i++){
					printf("Thong tin sinh vien thu: %d\n",i);
					 nhap();
				}
				
				break;
			case 2:
				xuat(p);
				break;
//			case 3:
//				printf("Nhap so can them: ");
//				scanf("%d", &ad);
//				p = addduoi(p,ad);
//				break;
//			case 4:
//				printf("Chon vi tri can them: ");
//				scanf("%d",&a);
//				printf("Nhap so muon them: ");
//				scanf("%d",&so);
//				p = addvt(p,a,so);
//				break;
//			case 5:
//				printf("Chon vi tri can xoa: ");
//				scanf("%d",&vt);
//				 p= xoa(p,vt);
//				 break;
//			case 6:
//				printf("Nhap so can tim: ");
//				scanf("%d",&tim);
//				find(p,tim);
//				break;
//			case 7:
//				return 0;
			default: return 0;
		}
	}
}
