#include<stdio.h>
struct list{
	char ten[50];
	char nsinh[20];
	char gtinh[5];
	float toan;
	float li;
	float hoa;
};
typedef struct list *node;
struct sv{
	char ten[50];
	char nsinh[20];
	char gtinh[5];
	float toan;
	float li;
	float hoa;
};
node create(){
	printf("Ten: ");
	fflush(stdin);
}
int main(){
	node p = (node) malloc(sizeof(struct list));
	p =NULL;
	insert(p);
}
