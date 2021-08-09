#include<stdio.h>
struct list{
	int data;
	struct list *next;
};
typedef struct list *node;
node tao(char gt){
	node tam;
	tam = (node)malloc(sizeof(struct list));
	tam->next = NULL;
	tam->data =gt;
	return tam;
}
node listKe(node dau,char gt){
	node tam = tao(gt);
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
void xuat(node dau){
	node run = dau;
	if(run!= NULL){

		while(run!=NULL){
			printf("%c ",run->data);
			run = run->next;
		}
		printf("\n");
	}
}
void matranKe(){
	int i,j;
	int arr[7][7] = {{0, 1, 0, 1, 0, 0, 0},
					 {1, 0, 1, 1, 1, 0, 0},
					 {0, 1, 0, 0, 1, 0, 0},
					 {1, 1, 0, 0, 1, 1, 0},
					 {0, 1, 1, 1, 0, 1, 1},
					 {0, 0, 0, 1, 1, 0, 1},
					 {0, 0, 0, 0, 1, 1, 0},
					 };

    for(i=0; i<7; i++)
    {
        for(j=0; j<7; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}
void matranTrongso(){
	int i,j;
	int arr[7][7] = {{0, 6, 0, 4, 0, 0, 0},
					 {6, 0, 7, 8, 6, 0, 0},
					 {0, 7, 0, 0, 4, 0, 0},
					 {4, 8, 0, 0, 14, 5, 0},
					 {0, 6, 4, 14, 0, 7, 8},
					 {0, 0, 0, 5, 7, 0, 10},
					 {0, 0, 0, 0, 8, 10, 0},
					 };

    for(i=0; i<7; i++)
    {
        for(j=0; j<7; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
	node p = (node)malloc(sizeof(struct list));
	p = NULL;
	matranKe();
	printf("\n--------------------------------\n");
	matranTrongso();
	printf("\n--------------------------------\n");
	printf("Danh sach ke cua A:  ");
	p=listKe(p,'A');
	p=listKe(p,'B');
	p=listKe(p,'D');
	xuat(p);
	p = NULL;
	printf("\nDanh sach ke cua B:  ");
	p=listKe(p,'B');
	p=listKe(p,'A');
	p=listKe(p,'C');
	p=listKe(p,'D');
	p=listKe(p,'E');
	xuat(p);
	p = NULL;
	printf("\nDanh sach ke cua C:  ");
	p=listKe(p,'C');
	p=listKe(p,'B');
	p=listKe(p,'E');
	xuat(p);
	p = NULL;
	printf("\nDanh sach ke cua D:  ");
	p=listKe(p,'D');
	p=listKe(p,'A');
	p=listKe(p,'B');
	p=listKe(p,'E');
	p=listKe(p,'F');
	xuat(p);
	p = NULL;
	printf("\nDanh sach ke cua E:  ");
	p=listKe(p,'E');
	p=listKe(p,'B');
	p=listKe(p,'C');
	p=listKe(p,'D');
	p=listKe(p,'F');
	p=listKe(p,'G');
	xuat(p);
	p = NULL;
	printf("\nDanh sach ke cua F:  ");
	p=listKe(p,'F');
	p=listKe(p,'D');
	p=listKe(p,'E');
	p=listKe(p,'G');
	xuat(p);
	p = NULL;
	printf("\nDanh sach ke cua G:  ");
	p=listKe(p,'G');	
	p=listKe(p,'E');
	p=listKe(p,'F');
	xuat(p);
}
