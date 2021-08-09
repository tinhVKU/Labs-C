#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char data;
    struct node* left;
    struct node* right;
};
struct stack {
	int data;
	struct stack* next;
};
typedef struct stack* Stack;
static char postfix[] = "";
Stack createNode(int n){
	Stack temp = (Stack)malloc(sizeof(struct stack));
	temp->data = n;
	temp->next = NULL;
	return temp;
}

Stack push(Stack s,int n){
	Stack temp = createNode(n);
	if (!s){
		s = temp;
	} else {
		temp->next = s;
		s = temp;
	}
	return s;
}

int top(Stack s){
	if (s) return s->data;
	return 0;
}

Stack pop(Stack s){
	int n = s->data;
	Stack temp = s;
	s= s->next;
	free(temp);
	return s;
}

struct node* newNode(char data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%c", node->data);
 
    printPreorder(node->left);
 
    printPreorder(node->right);
}
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
 
    printPostorder(node->right);
 
    printf("%c", node->data);
    char c = node->data;
	strncat(postfix, &c, 1);
}
void infix(struct node* node){
	if(node == NULL)
		return;
	if(node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/' || node->data == '^'){
		printf("(");
	}
	infix(node->left);
 
    printf("%c ", node->data);
 
    infix(node->right);
    
    if(node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/' || node->data == '^'){
    	printf(")");
	}
    
}
int postfixValue(char str[]){
	Stack stack = NULL;
	int i;
	int len = strlen(str);
	for ( i=0;i<len;i++){
		if (str[i]>='0' && str[i]<='9'){
			stack = push(stack,(int)str[i]-'0');
		}else {
			int a = top(stack);
			stack = pop(stack);
			int b = top(stack);
			stack = pop(stack);
			switch (str[i]){
				case '+':
					stack = push(stack,a+b);
					break;
				case '-':
					stack = push(stack,b-a);
					break;
				case '*':
					stack = push(stack,a*b);
					break;
				case '/':
					stack= push(stack,b/a);	
			}
		}
	}
	return top(stack);
}
 
int main()
{
    struct node* root = newNode('2');
    root->left = newNode('7');
    root->right = newNode('5');
    root->left->left = newNode('2');
    root->left->right = newNode('11');
    root->left->left->left = newNode('6');
	root->left->left->right = newNode('5');
//    root->left->right->left = newNode('b');
//    root->left->right->right = newNode('c');
//    
// 	root->right->left = newNode('+');
 	root->right->right = newNode('9');
 		root->right->right->right = newNode('4');
//	root->right->left->left = newNode('4');
//	root->right->left->right = newNode('2');
//	
    printf("\n\tPrefix:   ");
    printPreorder(root);
 
    printf("\n\tInfix:   ");
    infix(root);
    
    printf("\n\tPostfix:   ");
    printPostorder(root);
	printf("\n\tPostfix value: %d",postfixValue(postfix));
	printf("\n");
    return 0;
}
