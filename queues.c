#include<stdio.h>
int s[100];
int rear=-1;
int front=0;
void enqueues(int x){
	rear++;
	s[rear]=x;
}
int dequeues(){
	
	int x = s[front];
    front ++;

    return x;
}
void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d",s[i]);
	}

}
int main(){
	enqueues(3);
	enqueues(2);
	enqueues(1);
	dequeues();
//printf("%d",dequeues());
//printf("%d",dequeues());
//printf("\n");
	display();
	
	
}
