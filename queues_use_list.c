#include<stdio.h>
#include<malloc.h>
struct list{
	int data;
	struct node *next;	
};
typedef struct list *node;
node create(int x){
	node tam = (node)malloc(sizeof(struct list));
	tam->data=x;
	tam->next = NULL;
	return tam;
}
node enqueues(node head,int x){
	node tam = create(x);
	if(head == NULL){
		head=tam;
	}else{
		node run= head;
		while(run->next!=NULL){
			run=run->next;
		}
		run->next = tam;
	}
	return head; 
}
node dequeues(node head){
	if(head==NULL){
		printf("The list is empty!\n");
	}
	else{
		int y =head->data;
		head=head->next;
		printf("%d\n",y);
	}
	return head;
}
void display(node head){
	if(head == NULL){
		printf("The list is empty!\n");
	}else{
			node run = head;
		while(run!=NULL){
		printf("%d ",run->data);
		run = run->next;
		}
		printf("\n");
	}
}
int main(){
	node p = (node) malloc(sizeof(struct list));
	p= NULL;
	int n,a;
	printf("---FIRST IN FIRST OUT---\n");
	printf("\t Cac Chuc nang: \n");
	printf("\t1.Them vao (o sau)\n");
	printf("\t2.Lay ra (o truoc)\n");
	printf("\t3.Hien thi danh sach\n");
	
	while(1){
		printf("Moi nhap chuc nang: ");
		scanf("%d",&n);
		switch(n){
		case 1:
			printf("Nhap so: ");
			scanf("%d",&a);
			p= enqueues(p,a);
			break;
		case 2:
			p= dequeues(p);
			break;
		case 3:
			display(p);
			break;
		default: return 0;	
	}
	}

//	p= enqueues(p,1);p= enqueues(p,2);p= enqueues(p,3);p=enqueues(p,4);
//	p= dequeues(p);
//	display(p);
}
