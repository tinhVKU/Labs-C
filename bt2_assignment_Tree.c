#include <stdio.h>
#include <stdlib.h>
struct node 
{
    char data;
    struct node *left;
    struct node* right;
};
static int count = 0;
int getLeafCount(struct node* node)
{
  	if(node == NULL)       
    	return 0;
  	if(node->left == NULL && node->right==NULL)      
    	return 1;            
  else 
    	return 	getLeafCount(node->left)+
           		getLeafCount(node->right);      
}
int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int countnodes(struct node *root)
{
	
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
struct node* newNode(char data) 
{
  	struct node* node = (struct node*)
                       	malloc(sizeof(struct node));
  	node->data = data;
  	node->left = NULL;
  	node->right = NULL;
    
  	return(node);
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

	printf("\n");   
  	printf("\tTree co %d la\n", getLeafCount(root));
	printf("\tChieu cao cua Tree la %d\n", maxDepth(root));
	printf("\tTree co %d node\n",countnodes(root));
 
  	return 0;
}
