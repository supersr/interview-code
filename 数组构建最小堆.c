// 给定一个数组，A[1..n], 转化成一个最小值堆。
#include<stdio.h>
void Max_Heapify(int* A, int i,int length){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;
	int b;
	if(l < length && A[l] > A[i]){
		largest = l;
	}
	else{
		largest = i;
	}
	if(r < length && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		b = A[largest];
		A[largest] = A[i];
		A[i] = b;
		Max_Heapify(A, largest, length);

	}


}
int main(){
	int A[5] = {1,2,3,4,5};
	int length = 5;
	int i;
	for(i = length / 2 - 1; i >= 0; i --){

		Max_Heapify(A,i,length);
	}
	for(i = 0; i < 5;i++){
		printf("%d",A[i]);
	}
}