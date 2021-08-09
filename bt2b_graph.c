#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7
struct Vertex {
   char label;
   bool visited;
};
int stack[MAX]; 
int top = -1; 
struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;
void push(int item) { 
   stack[++top] = item; 
} 
int pop() { 
   return stack[top--]; 
} 
int peek() {
   return stack[top];
}
bool isStackEmpty() {
   return top == -1;
}
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
} 
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}
void depthFirstSearch() {
   int i;
   lstVertices[0]->visited = true;
   displayVertex(0);   
   push(0);

   while(!isStackEmpty()) { 
      int unvisitedVertex = getAdjUnvisitedVertex(peek());
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }       
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }        
}
int main() {
   int i, j;

   for(i = 0; i < MAX; i++)   
      for(j = 0; j < MAX; j++) 
         adjMatrix[i][j] = 0;
   
	addVertex('B');// 3
  	
  	addVertex('A');// 1
  	addVertex('F');// 2
	addVertex('D');// 0
	addVertex('E');// 4 
  	addVertex('G');// 5    
   	addVertex('C');// 6
   
   	addEdge(0, 1);    
   	addEdge(0, 3);  
   	addEdge(0, 4);    
   	addEdge(0, 2);        
   	addEdge(1, 3);   
   	addEdge(1, 0);    
  	addEdge(2, 0);    
   	addEdge(2, 4);  
   	addEdge(2, 5);   
   	addEdge(3, 1);
    addEdge(3, 6);
    addEdge(3, 0);
    addEdge(3, 4);
   	addEdge(4, 3);    
   	addEdge(4, 6);    
   	addEdge(4, 0);    
   	addEdge(4, 2); 
   	addEdge(4, 5);    
   	addEdge(5, 4);    
   	addEdge(5, 2);    
   	addEdge(6, 3);  
   	addEdge(6, 4);    

   printf("Depth First Search: ");
   depthFirstSearch(); 

   return 0;   
}
