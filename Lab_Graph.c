#include<stdio.h>
#include<stdlib.h>
int n = 5;
//int A[5][5]= {{0,1,1,1,1},
//			{1,0,1,0,0},
//			{1,1,0,1,0},
//			{1,0,1,0,1},
//			{1,0,0,1,0}	};
int A[5][5]={{0,4,8,3,2},
			{4,0,3,0,0},
			{8,3,0,5,0},
			{3,0,5,0,6},
			{2,0,0,6,0}	};
//int n = sizeof(A)/sizeof(int);
char V[] = {'A','B','C','D','E'};
int bangmau[5];//khai bao bang mau de to mau cac dinh
//khai bao queue gom co cac thao tac: enqueue, dequeue,isEmpty
int Q[20];
int front, rear;
void khoitao(int Q[]){
	front = rear = 0;
}
int isEmpty(int Q[]){
	return (front == rear);//neu front = rear thi Q rong la dung
//	if(front==rear)
}
void enqueue(int x,int Q[]){
	Q[rear]= x;
	rear= rear+1;
}
int dequeue(int Q[]){
	int x = Q[front];
	front = front +1;
	return x;
}
void BFT(int k,int n,int A[][n]){	//duyet rong xuat phat tu dinh k
	khoitao(Q);					//B1 khoi tao Q
	int j;
	for(j=0;j<n;j++){			//Khoi tao bang mau
		bangmau[j] = 0;
	}
								
	enqueue(k,Q);
	bangmau[k] = 1;				//B2 dua dinh k vao Q
	while(isEmpty(Q)==0){		//B3 lap lai cho den khi Q rong
		int i = dequeue(Q);		//B3.1 Lay 1 dinh o dau QUeue ra 
		for(j = 0;j<n;j++){		//
//			if(A[i][j]==1&& bangmau[j]==0){
			if(A[i][j]!=0&& bangmau[j]==0){
				enqueue(j,Q);
				bangmau[j] = 1;
			}
			
		}
		printf("%c ",V[i]);
	}
}
void DFTDequy(int k,int BM[] ,int n,int A[][n]){
	printf("%c ",V[k]);
	BM[k]=1;
	int j;
	for(j=0;j<n;j++){
		if(A[k][j]!=0&&BM[j]==0)
			DFTDequy(j,BM,n,A);
	}
}
void DFT(int k,int n,int A[][n]){
	int j=0;
	for(j=0;j<n;j++){
		bangmau[j]=0;
	}
		
	DFTDequy(k,bangmau,n,A);
}
//void in(){
//	int i,j;
//	for( i = 0; i < 5; i++)
//   {
//      for( j = 0; j < 5; j++)
//         printf("%d\t", A[i][j]);
//      printf("\n");
//   }
//}
int main(void){
	int k= 0;
	printf("\n BFT(%c): ",V[k]);
	BFT(k,n,A);
	printf("\n DFT(%c): ",V[k]);
	DFT(k,n,A);
	 k= 1;
		printf("\n BFT(%c): ",V[k]);
	BFT(k,n,A);
	printf("\n DFT(%c): ",V[k]);
	DFT(k,n,A);
	 k= 2;
		printf("\n BFT(%c): ",V[k]);
	BFT(k,n,A);
	printf("\n DFT(%c): ",V[k]);
	DFT(k,n,A);
	 k= 3;
	printf("\n BFT(%c): ",V[k]);
	BFT(k,n,A);
	printf("\n DFT(%c): ",V[k]);
	DFT(k,n,A);
	 k= 4;
		printf("\n BFT(%c): ",V[k]);
	BFT(k,n,A);
	printf("\n DFT(%c): ",V[k]);
	DFT(k,n,A);
	printf("\n-----------------\n");
//	in();
//	printf("Kich thuoc cua mang A: %d",n);
	return 0;
}
			
