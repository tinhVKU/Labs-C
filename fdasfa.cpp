#include<stdio.h>
#include<string.h>
char s[100];
int top = -1;
void push(char x){
		top ++;
		s[top]=x;	
}
char pop(){
	char x = s[top];
	top--;
	return x;
}
int KTngoac(char bt[]){
	int i = 0; 
	int dung =1;
	for(i=0;i<strlen(bt);i++){
		if(bt[i]=='('||bt[i]=='{')
			push(bt[i]);
			
		if(bt[i]==')'){
			char c = pop();
			if(c=='}')
			dung  = 0;
		}
		if(bt[i]=='}'){
			char c = pop();
			if(c==')')
			dung  = 0;
		}
	
	}	
	//het stack roi ma top van con
	if(top>-1){
		dung = 0 ;
	return dung;
	}
}
main(){
	char bt[20];
	gets(bt);
	int kt = KTngoac(bt);
	if(kt==1) printf("Hop le");
	else printf("Bieu thuc khong hop le");


                       
}
