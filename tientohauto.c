#include<stdio.h>
#include<string.h>
char s[100];
char in[100],tto[100];
int top = -1;
int dem = 0,tam=0;
void xuat(char x[]){

	in[dem]=x;
	dem++;
}
void tiento(char x[]){

	tto[tam]=x;
	tam++;
}
void push(char x){
		top ++;
		s[top]=x;	
}
int pop(){
	char x = s[top];
	top--;
	return x;
}   
main(){
	printf("--Chuong trinh chuyen trung to sang hau to va tien to--\n\n");
	printf("  chi ap dung cho bieu thuc co 1 toan tu '+' hoac '-'\n\n\n");
	char chuoi[100];
	printf("Nhap bieu thuc: ");
	gets(chuoi);
	int i ;
	
	for(i=0;i<strlen(chuoi);i++){
		
		int ascii_c = chuoi[i];
		if(ascii_c!=43 && ascii_c!=45)
			xuat(chuoi[i]);
		else{
			push(chuoi[i]);
		}		
	}
	while(top!= -1){
		in[dem]= pop();	
		dem++;
	}
	printf("Hau to: %s\n",in);
	char moi[100];
	int j=0;	
	for(i=(strlen(chuoi)-1);i>=0;i--){
		moi[j] = chuoi[i];
		j++;	
	}
	
	for(i=0;i<strlen(moi);i++){
		
		int ascii_c = moi[i];
		if(ascii_c!=43 && ascii_c!=45)
			tiento(moi[i]);
		else{
			
			push(moi[i]);
		}		
	}
	while(top!= -1){
		tto[tam]= pop();
		tam++;
	}
	int h=0;
	char truoc[100];
	for(i=(strlen(tto)-1);i>=0;i--){
		truoc[h] = tto[i];
		h++;	
	}
	printf("Tien to: %s\n",truoc);
	
	for(i=0;i<strlen(in);i++){
		if(in[i]!=43&& in[i]!=45)
			push(in[i]);
		else{
			if(in[i]==43){int l=0;int a[100];int bien;
					while(top!= -1){
			
						a[l]=(pop()-48);
						l++;
					}
					int o;
					for(o=0;o<l;o++){
						
						bien+=a[o];	
					}
				printf("Gia tri cua bieu thuc la: %d\n",bien);
			}
			if(in[i]==45){
				int l=0;int a[100];int bien;
					while(top!= -1){
			
						a[l]=(pop()-48);
						l++;
					}
					int o;
					bien=a[l-1];
					for(o=l-2;o>=0;o--){
						
						bien-=a[o];	
					}
				printf("Gia tri cua bieu thuc la: %d\n",bien);
				
			}
		}		
	}

}
