#include<iostream>  
using namespace std;  
//矩阵连乘求解 添加最优加括号方式 使乘法使用次数最少  
const int Q=10;  
//p为矩阵链，p[0],p[1]代表第一个矩阵，p[1],p[2]代表第二个矩阵，length为p的长度  
//所以如果有九个矩阵，length=10，m为存储最优结果的二维矩阵，s为存储选择最优结果路线的二维矩阵
//构造最优结果及路线方法  
void MatrixChainOrder(int *p,int m[Q][Q],int s[Q][Q],int length)  
{  
   for(int i = 0; i < length; i ++){
       m[i][i] = 0;
   }
   for(int r = 2; r< length; r++){
       for(int i = 1; i <= length - r + 1; i ++){
           int j = r + i - 1;
           m[i][j] = INT_MAX; //init
           for(int k = i; k < j; k++){
               int value = m[i][k] +m[k + 1][j] +p[i - 1] * p[k] * p[j];
               if(value < m[i][j]){
                   m[i][j] = value;
                   s[i][j] = k;
               } 
           }
       }
  }
}  
//打印分割位置及最优添括号方法  
void PrintAnswer(int s[Q][Q],int i,int j)  
{  
    if(i == j){
         printf("P%d",i);
    }
    else{
        printf("(");
        PrintAnswer(s,i,s[i][j]);
        PrintAnswer(s,s[i][j] + 1,j);
        printf(")");
    }
}  
int main()  
{  
    int p[Q]={28,30,15,45,5,10,20,25,15,18};  
    int m[Q][Q],s[Q][Q];  
    MatrixChainOrder(p,m,s,Q);  
    PrintAnswer(s,1,Q-1);  
    return 0;  
}  