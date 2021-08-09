#include<stdio.h>
//void themtrai(char tree[],int i){
//	char x;
//	print("Nhap so can them: ");
//	scanf("%c",&x);
//	tree[2*i+1]=x;
//}
//void themphai(char tree[],int i){
//	char x;
//	print("Nhap so can them: ");
//	scanf("%c",&x);
//	tree[2*i+2]=x;
//}
void duyetrong(char tree[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%c ",tree[i]);
	}
}

void duyetsau(char tree[],int n,int i){
	if(i<=n){
		if(tree[i]!=' ')
		printf("%c ",tree[i]);
		duyetsau(tree,n,2*i+1);
		duyetsau(tree,n,2*i+2);
	}
}
void duyetgiua(char tree[],int n,int i){
	if(i<=n){
		if(tree[i]!=' '){
			duyetgiua(tree,n,2*i+1);
			printf("%c ",tree[i]);
			duyetgiua(tree,n,2*i+2);
		}
	}
}
int main(){
	char tree[25];
	int j ;
	for(j=0;j<25;j++){
		tree[j]=' ';
	}
	tree[0]='*';
	tree[1]='-';
	tree[2]= '/';
	tree[3]='8';
	tree[4]='5';
	tree[5]='+';
	tree[6]='3';
	tree[11]='4';
	tree[12]='2';
//	duyetrong(tree,12);
	duyetsau(tree,15,0);
	printf("\n");
	duyetgiua(tree,15,0);
	return 0;
}
