#include<stdio.h>
int n = 8;
void in(int n,int A[]){
	int i;
	for(i=1;i<n;i++){
		printf("%d ",A[i]);
	}
}
void maxHeap(int n, int A[],int i){	//Xay dung max heap
	int largest;	//Bien chua so lon nhat --> Goc
	int left = 2*i;	//Nut trai
	int right = 2*i+1;	//Nut phai
	//B1 Tim so lon nhat de lam cha
	if(left<n&& A[left]>A[i])	//Con trai lon hon cha
		largest = left;			// lay con trai thay cha
	else{
		largest = i;
	}
	if(right< n&&A[right]>A[largest])	// Kiem tra con phai xem lon hown cha k
		largest = right;
	if(largest != i){
		int tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		maxHeap(n,A,largest);// Goi lai de quy de doi tiep
	}
}
void runMaxHeap(int A[],int n){
	int i;
	for(i = n/2;i>=1;i--){
		maxHeap(n,A,i);
	}
}


void minHeap(int n, int A[],int i){	//Xay dung max heap
	int small;	//Bien chua so nho nhat --> Goc
	int left = 2*i;	//Nut trai
	int right = 2*i+1;	//Nut phai
	//B1 Tim so nho nhat de lam cha
	if(left<n&& A[left]<A[i])	//Con trai nho hon cha
		small = left;			// lay con trai thay cha
	else{
		small = i;
	}
	if(right< n&&A[right]<A[small])	// Kiem tra con phai xem nho hown cha k
		small = right;
	if(small != i){
		int tmp = A[i];
		A[i] = A[small];
		A[small] = tmp;
		maxHeap(n,A,small);// Goi lai de quy de doi tiep
	}
}
void runMinHeap(int A[],int n){
	int i;
	for(i = n/2;i>=1;i--){
		minHeap(n,A,i);
	}
}
void HeapSort(int A[],int n){
	
	int i,j,tmp;
	runMaxHeap(A,n);	//B1 chay Maxheap
	for(i=n-1;i>0;i--){
		tmp = A[i];		//B2 Doi goc cho pt cuoi cung 
		A[i] = A[1];
		A[1] = tmp;
		runMaxHeap(A,i);//B3 Chay MaxHeap Cho pt con lai
	}
}
void HeapSortMin(int A[],int n){
	
	int i,j,tmp;
	runMinHeap(A,n);	//B1 chay Maxheap
	for(i=n-1;i>0;i--){
		tmp = A[i];		//B2 Doi goc cho pt cuoi cung 
		A[i] = A[1];
		A[1] = tmp;
		runMinHeap(A,i);//B3 Chay MaxHeap Cho pt con lai
	}
}
void deleteRoot(int arr[], int n){// B1 Xoa goc bang cach cho nut cuoi len thay
    int lastElement = arr[n - 1];  
    arr[1] = lastElement;
     n = n - 1; // B2 Giam kich thuoc 1
    runMaxHeap(arr,n);	// B3 Chay lai Heap
}
void insertNode(int arr[], int n, int Key){
    // B1 Tang kich thuoc len 1
    n = n + 1;
    // B2 Them x vao cuoi
    arr[n-1] = Key;
    // B3 Chay lai heap
    runMaxHeap(arr,n);
}
int main(){
	int A[] = {0,8,7,2,1,3,6,4};
	runMaxHeap(A,n);
	printf("\nMang sau khi chay MaxHeap: ");
	in(n,A);
	runMinHeap(A,n);
	printf("\nMang sau khi chay MinHeap: ");
	in(n,A);
	HeapSort(A,n);
	printf("\nMang sau khi chay HeapSort: ");
	in(n,A);
	HeapSortMin(A,n);
	printf("\nMang sau khi chay HeapSort: ");
	in(n,A);
	deleteRoot(A, n);
	printf("\nMang sau khi chay Delete: ");
	in(n,A);
	int Key =15;
	insertNode(A, n, Key);
	printf("\nMang sau khi chay Insert: ");
	in(n,A);
}
