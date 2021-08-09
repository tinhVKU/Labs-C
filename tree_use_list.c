#include <stdio.h>
#include <stdlib.h>
struct node {
    char data;
    struct node* left;
    struct node* right;
};
//void printGivenLevel(struct node* root, int level);
//int height(struct node* node);
//struct node* newNode(char data);
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
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
struct node* newNode(char data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
 
    printPostorder(node->right);
 
    printf("%c ", node->data);
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
 
    printf("%c ", node->data);
 
    printInorder(node->right);
}
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%c ", node->data);
 
    printPreorder(node->left);
 
    printPreorder(node->right);
}
int timMin(struct node* node){
	char m = node->data;
	while(node->left!=NULL){
		m = node->left->data;
		node = node->left;
	}
	return m;
} 
int timMax(struct node* node){
	char m = node->data;
	while(node->right!=NULL){
		m = node->right->data;
		node = node->right;
	}
	return m;
}
int main()
{
    struct node* root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->right = newNode('D');
    root->left->right->left = newNode('G');
    root->left->right->left->left = newNode('I');
 	root->right->left = newNode('E');
 	root->right->right = newNode('F');
 	root->right->left->right = newNode('H');
 	root->right->left->right->left = newNode('J');
 	root->right->left->right->right = newNode('K');
    printf("\nPre-Order: \n");
    printPreorder(root);
 
    printf("\nIn-Order: \n");
    printInorder(root);
 
    printf("\nPost-Order: \n");
    printPostorder(root);
    
    printf("\nLevel-order traversal: \n");
    printLevelOrder(root);
    
    printf("\nMin: %c\n",timMin(root));
     printf("\nMax: %c\n",timMax(root));
    getchar();
    return 0;
}
