#include<stdio.h>

int H[11];
int HF(int x){
	return x%10;
}
void Bam(int x){
	int i = HF(x);
	while(H[i]!=0){
		i++;
		if(i>10){
			 i=0;
		}
	}
	H[i] = x;
}
void InBangBam(){
	int i ;
	for(i=0;i<=10;i++){
		printf("%d ",H[i]);
	}
}

void TK(int x){
	int i = HF(x);
	int kq=H[i];
	if(x==kq)
		printf("\nTim thay %d tai o so %d",x,i);
}
int main(){
	Bam(17);Bam(12);Bam(26);Bam(42);Bam(23);Bam(18);
	Bam(22);Bam(9);Bam(16);Bam(35);Bam(15);
	InBangBam();
	TK(10);
} 
