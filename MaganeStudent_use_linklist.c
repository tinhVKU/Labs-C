#include<stdio.h>
#include<malloc.h>
//#include<stdlib.h>
//
//#include<string.h>
struct list{
	char ten[50];
	
	float toan;
	struct list *next;
};
typedef struct list *node;
struct {
	char ten[50];
	
	float toan;

}sv;
node create(){
	printf("Ten: ");
	fflush(stdin);
	gets(sv.ten);
	printf("Diem: ");
	scanf("%f",&sv.toan);
	node tam;
	tam= (node) malloc(sizeof(struct list));
	tam->next= NULL;
	strcpy(tam->ten,sv.ten);
	tam->toan = sv.toan;
	
	return tam;
}
node insert(node head){
	node tam =create();
	if(head==NULL){
	
	 head=tam;
	}
	else{
		tam->next= head;
		head= tam;
	}
	return head;
}
void display(node head){
	node run = head;
	if(run!= NULL){
		printf("\tThong tin sinh vien\n");
		while(run!=NULL){
			printf("\nTen: ");
			puts(run->ten);
			printf("Toan: %.2f ",run->toan);
			run=run->next;	
		}
		printf("\n");
	}
}
int main(){
	node p = (node) malloc(sizeof(struct list));
	p =NULL;

	int n;

	while(1){
		printf("So: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				p= insert(p);
				break;
			case 2: 
				display(p);
				break;
		}
	}
}
