#include <stdio.h>
#include <stdlib.h>
struct node {
    char data;
    struct node *left;
    struct node* right;
};
struct node *Q[20];
int front,rear;
static int dem,f=0;
//int ktRong(struct node *Q[]);
//void KhoiTao(struct node *Q[]);
//void enqueue(struct node *p,struct node *Q[]);
//struct *dequeue(struct node *Q[]);
struct node* taoNode(int data,struct node *T){
  	struct node* node = (struct node*)
                       	malloc(sizeof(struct node));
  	node->data = data;
  	node->left = NULL;
  	node->right = NULL;
  	if(T==NULL)
  		T= node;
	else{
		if(data==T->data)
			printf("Gia tri da ton tai./n");
		else{
			if(data<T->data)
				T->left = taoNode(data,T->left);
			else
				T->right = taoNode(data,T->right);
		}
	}
	return T;
}
void Preorder(struct node* T){
    if (T == NULL)
        return;
    printf("%d ", T->data);
 
    Preorder(T->left);
 
    Preorder(T->right);
}
void Inorder(struct node* T){
    if (T == NULL)
        return;
    Inorder(T->left);
 
    printf("%d ", T->data);
 
    Inorder(T->right);
}
void Postorder(struct node* T){
    if (T == NULL)
        return;
    Postorder(T->left);
 
    Postorder(T->right);
 
    printf("%d ", T->data);
}
int ktRong(struct node *Q[]){
	if(front == rear)
		return 1;
	else
		return 0;
}
void KhoiTao(struct node *Q[]){
	front = rear = 0;
}
void enqueue(struct node *p,struct node *Q[]){
	Q[rear] = p;
	rear = rear +1;
}
struct node *dequeue(struct node *Q[]){
	struct node *p = Q[front];
	front = front +1;
	return p;
}
void BFT(struct node *T){//duyet rong
	KhoiTao(Q);				//KHoi tao Q rong
	enqueue(T,Q);
	while(ktRong(Q)==0){
		struct node *p = dequeue(Q);
		if(p->left != NULL)
			enqueue(p->left,Q);
		if(p->right != NULL)
			enqueue(p->right,Q);
		printf("%d ",p->data);
	}

}
int timMin(struct node* T){
	int m = T->data;
	while(T->left!=NULL){
		m = T->left->data;
		T = T->left;
	}
	return m;
} 
int timMax(struct node* T){
	int m = T->data;
	while(T->right!=NULL){
		m = T->right->data;
		T = T->right;
	}
	return m;
}
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
int DemNode(struct node *T)
{
	
    if(T != NULL)
    {
        DemNode(T->left);
        dem++;
        DemNode(T->right);
    }
    return dem;
}
struct node *dele(int x,struct node *T){
	if(T==NULL)
		return T;
	if(x<T->data)
		T->left = dele(x,T->left);
	else
		if(x> T->data)
			T->right = dele(x,T->right);
		else{
			//3 truong hop
			// + chi co con trai
			// + chi co con phai
			// + co ca hai con
			if(T->right==NULL)
				return T->left; //con trai len thay
			else if(T->left == NULL)
				return T->right; //con phai len thay
			else{
				int MaxTrai = timMin(T->right);//Tim node lon nhat ben trai
				T->data = MaxTrai;
				dele(MaxTrai, T->left); //Lay len thay roi nen can xoa di
				
			}
			
		}
		return T;
}
int countNonleaf(struct node* T){
    if (T == NULL || (T->left == NULL && T->right == NULL))
        return 0;
    return /*1+*/countNonleaf(T->left) + 
               countNonleaf(T->right);
}
int tim(struct node* T,int x){
//	int f = 0;
	if(x==T->data)
		f=1;
	else{
		if(x< T->data)
		f=	tim(T->left,x);
		else
		f=	tim(T->right,x);
	}
	return f;
} 
int main(){
	int a,b;
	struct node *root = NULL;
	root = taoNode(8,root);
	root = taoNode(3,root);
	root = taoNode(1,root);
	root = taoNode(6,root);
	root= taoNode(4,root);
	root = taoNode(7,root);
	root = taoNode(10,root);
	root = taoNode(9,root);
	root = taoNode(14,root);
	root = taoNode(13,root);
	
	printf("\nPre-Order: \n");
    Preorder(root);
    
    printf("\nIn-Order: \n");
    Inorder(root);
    
    printf("\nPost-Order: \n");
    Postorder(root);
    
    printf("\nLevel-order traversal: \n");
    BFT(root);
	
	printf("\nMin: %d\n",timMin(root));
    printf("Max: %d\n",timMax(root));
    printf("Do cao: %d\n",height(root));
    printf("Tree co %d Node\n",DemNode(root));
    printf("Nhap phan tu muon xoa: ");
    scanf("%d",&a);
    dele(a,root);
    printf("Tree sau khi xoa: \n");
    BFT(root);
    printf("\nSo Node con: %d\n",countNonleaf(root));
    printf("Nhap phan tu muon tim: ");
    scanf("%d",&b);
    if(tim(root,b)==1)
    	printf("Tim Thay");
    else{
    	printf("Khong tim Thay");
	}
} 
