#include<stdio.h>
#include<malloc.h>

struct doublelist{
	int data;
	struct doublelist *next;
	struct doublelist *pre;
};
typedef struct doublelist *node;
struct List{
	node *head;
	node *tail;
};
typedef struct List list;
node create(int gt){
	node tam;
	tam = (node) malloc(sizeof(struct doublelist));
	tam->next=NULL;
	tam->pre = NULL;
	tam->data=gt;
	return tam;
}
node addfirst(list *l,int gt){
	node tam = create(gt);
	if(l->head==NULL ){	
		l->head = tam;
		l->tail = tam;
		
	}
	else{
		tam->next= l->head;
		node temp = l->head;
		temp->pre = tam;
		l->head = tam;

	}
	return tam;
}
node addlast(list *l,int value){
	
	node tam = create(value);
	if(l->head==NULL ){	
		l->head = tam;
		l->tail = tam;
	}
	else{	
		node temp = l->tail;
		tam->pre = temp;	
		temp->next = tam;
		l->tail = tam;
	}
	return tam;
}
node add(list *l){
	if(l->head!=NULL){
		int vt,a;
		printf("Chon vi tri can them: ");
		scanf("%d",&vt);
		printf("So can them: ");
		scanf("%d",&a);
		node tam = create(a);
		node start = l->head;
		int dem = 1;
		while(start!= l->tail){
			start= start->next;
			dem++;
		}
		if(vt==1){
			addfirst(l,a);
		}
	
		else if(vt>dem){
			addlast(l,a);
		}
		else{
			int i;
			node run = l->head;
			for(i=1;i<vt-1;i++){
				run = run->next;
				
			}
			tam->pre = run;
			tam->next= run->next;
			run->next->pre =tam;
			run->next = tam;
		}
	}
	else{
		
		printf("Mang Rong!\n");
	}
	
}
node deletefirst(list *l){
	int dem = 0;
	node run = l->head;
	while(run!=NULL){
		dem++;
		run = run->next;
	}
	if(dem==1){
		l->head=NULL;
	}
		else if(dem==0){
			printf("Mang rong! Khong the xoa\n");
		}
	else{
		node temp = l->head;
		temp = temp->next;
		temp->pre = NULL;
		l->head = temp;
		return temp;
	}
}
node deletelast(list *l){
	int dem = 0;
	node run = l->head;
	while(run!=NULL){
		dem++;
		run = run->next;
	}
	if(dem==1){
		l->head=NULL;
	}
		else if(dem==0){
			printf("Mang rong! Khong the xoa\n");
		}
	else{
		node temp = l->tail;
		temp->pre->next= NULL;
		
		l->tail = temp->pre;
		return temp;
	}
}
node xoaposible(list *l){
	if(l->head!=NULL){
		int vt,a;
		printf("Chon vi tri can xoa: ");
		scanf("%d",&vt);
		node start = l->head;
		int dem = 1;
		while(start!= l->tail){
			start= start->next;
			dem++;
		}
		if(vt==1){
			deletefirst(l);
		}
	
		else if(vt>=dem){
			deletelast(l);
		}
		else{
			int i;
			node run = l->head;
			for(i=1;i<vt;i++){
				run = run->next;
				
			}
			run->pre->next = run->next;
			run->next->pre = run->pre;
		}
	}
	else{
		
		printf("Mang Rong!\n");
	}
}
node findnumber(list *l,int b){
		int dem=1,tam=0;
	node run = l->head;
	if(run!= NULL){

		while(run!=NULL){	
			if(run->data==b){
				printf("Tim thay so %d o vi tri thu %d\n",b,dem);
				tam++;
				break; 
			}
			run = run->next;
			dem++;
		}
		if(tam==0){
				printf("Khong tim thay!\n");
		}
	}
	else{
		printf("Khong tim thay!\n");
	}	
}
node findposible(list *l,int c){
		int dem=1,i,tam=0;

	if(c==0){
		printf("Khong tim thay!\n");
	} 
	
	else{
		node run = l->head;
		if(run!= NULL){
			node run = l->head;
			while(run!= l->tail){
				run= run->next;
				dem++;
			}
			if(c>dem){
				printf("Khong tim thay!\n");
			}
			else{
				node start = l->head;
				for(i=1;i<c;i++){
					start = start->next;
				
				}
					printf("So ban dang can tim la: %d\n",start->data);
			}
		
		}
		else{
			printf("Khong tim thay!\n");
		}	
	}
	
}
void display(list *l){
	
	node run = l->head;
	if(run!= NULL){

		while(run!=NULL){
			printf("%d ",run->data);
			run = run->next;
		}
	printf("\n");
	}
	else printf("Mang rong!\n");	
}
node count(list *l){
	node start = l->head;
	int dem = 1;
	while(start!= l->tail){
		start= start->next;
		dem++;
	}
	printf("So Phan tu hien co la: %d\n",dem);
}
void print(){
	printf("\t\t\t\t========DANH SACH LIEN KET DOI========\n\n\t\t\t\t");
	printf("Cac chuc nang chinh cua chuong trinh\n\t\t\t\t");
	printf("--------------------------------------\n\t\t\t\t");
	printf("!       1.Them so vao dau     	     !\n\t\t\t\t");	
	printf("!       2.Them so vao cuoi     	     !\n\t\t\t\t");
	printf("!       3.Them so vao giua   	     !\n\t\t\t\t");
	printf("!       4.Xoa so dau        	     !\n\t\t\t\t");
	printf("!       5.Xoa so duoi       	     !\n\t\t\t\t");
	printf("!       6.Xoa vi tri tuy chon  	     !\n\t\t\t\t");
	printf("!       7.Tim kiem theo gia tri	     !\n\t\t\t\t");
	printf("!       8.Tim kiem theo vi tri	     !\n\t\t\t\t");
	printf("!       9.Dem so luong cac phan tu   !\n\t\t\t\t");
	printf("!       10.Xuat ra man hinh          !\n\t\t\t\t");
	printf("!       11.Thoat chuong trinh        !\n\t\t\t\t");
	printf("--------------------------------------\n");
}

int main(){
	list l;
	l.head = l.tail = NULL;

	print();
	int n,gt,value,b,c;
	while(1){
		printf("Moi ban chon chuc nang: ");
		scanf("%d",&n);
		switch(n){
			case 1: 
				printf("Nhap so can them: ");
				scanf("%d", &gt);
				addfirst(&l,gt);
					break;
			case 2:
				printf("Nhap so can them: ");
				scanf("%d", &value);
				addlast(&l,value);
					break;
			case 3:
				add(&l);
				break;
			case 4:
				printf("Xoa dau\n");
				deletefirst(&l);
				break;
			case 5:
				printf("Xoa duoi\n");
				deletelast(&l);
				break;
			case 6:
				xoaposible(&l);
				break;
			case 7:
				printf("Nhap gia tri can tim: ");
				scanf("%d",&b);
				findnumber(&l,b);
				break;
			case 8:
				printf("Nhap vi tri can tim: ");
				scanf("%d",&c);
				findposible(&l,c);
				break;
			case 9:
				count(&l);
				break;
			case 10:
				display(&l);
				break;
			case 11:
				return 0;
			default:
				return 0;
	}
	}
	
}
