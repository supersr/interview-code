#include<stdio.h>
int main(){
	//假设01子串为不符合要求
	char* input = "123";
   
    int a[100];
    int num[100];
    int i;
    int length;
    for(length = 0; input[length] != '\0'; length ++){   
        num[length] = input[length] - '0';
    }
    if(num[0] == 0){
        return 0;
    }
    else{
        a[0] = 1;  
    }

    a[1] = 0;
    if(num[1] != 0){
        a[1] += a[0];
    }
    if(num[0]* 10 + num[1] <= 26 && num[0] * 10 + num[1] > 0)  {
        a[1] +=  1;
    }

    for(i = 2; i < length; i++){
        a[i] = 0;
        if(num[i] != 0){
            a[i] += a[i - 1];
        }
        
        if(num[i - 1] != 0){
            if(num[i - 1]* 10 + num[i] <= 26 && num[i - 1] * 10 + num[i] > 0)  {
                a[i] +=  a[i - 2]; 
            }
        }

    }
    printf("%d", a[length - 1]);
  
}

