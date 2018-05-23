#include <stdio.h>
#include <malloc.h>
int max(int f1, int f2, int f3, int f4){
    int max = f1;
    if(max < f2){
        max = f2;
    }
    if(max < f3){
        max = f3;
    }
    if(max < f4){
        max = f4;
    }
    return max;
}
int main() {
    int numA,numB,numC,numD,mA,mB,mC,mD;
    scanf("%d%d%d%d%d%d%d%d",&numA,&numB,&numC,&numD,&mA,&mB,&mC,&mD);
    printf("sss\n");
    
}