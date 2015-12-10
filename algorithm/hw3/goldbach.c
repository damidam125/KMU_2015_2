/*********************
20123434 Ȳ����
Problem E - Goldbach��s Conjecture


*********************/
#include <stdio.h>
#define false 0
#define true 1
#define MAXINPUT 1000

/************
parameter ����n�� �Ҽ����� �ƴ����� �Ǻ��ϴ� �Լ�.
************/
int is_prime(int n){
	int i;
	if(n==2)
		return true;
	if ( n%2 == 0)
		return false;
	for(i=3; i*i<n+1; i+=2)
		if(n%i==0)
			return false;
	return true;
}


/************
parameter-
	arr[] : arr[i]���� ����i�� �Ҽ����� �ƴ����� �����ϰ� ����. ex_arr[2]=1,  arr[3]=1, arr[4]=0
	num : golabach�� ã�� n
	idx1, idx2 : arr�� �ε����� 2��

algorithm
1) basics
	for every idx1 and idx2 where idx1+idx2==num:
		if both idx1 and idx2 are prime number then print idx1 and idx2
2) recursive
	if arr[idx1]==1 && arr[idx2]==1 then
		print idx1 and idx2
		return
	else
		return recursivefunc(arr, num, idx1-1, idx2+1) 
************/
void getGoldbach(int arr[MAXINPUT], int num, int idx1, int idx2){
	if( arr[idx1] && arr[idx2] ){
		printf("%d %d\n", idx1, idx2);
		return ;
	}
	else return getGoldbach(arr, num, idx1-1, idx2+1);
}

int main(void){
	FILE *fp = fopen("input.txt", "r");
	int arr[MAXINPUT+1] = {0};
	int i;
	int numcase;

	//set the prime flag for every integer between 0 to 1000
	for(i=0; i<=MAXINPUT; i++){
		arr[i]=is_prime(i);
	}

	fscanf(fp, "%d", &numcase);
	for(i=0; i<numcase; i++){
		int num;
		fscanf(fp, "%d", &num);
		getGoldbach(arr, num, num/2, num-num/2); //get goldbach
	}
}