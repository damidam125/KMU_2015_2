/*********************
20123434 황정담
Problem E - Parenthesis

괄호가 알맞게 닫혔는지 확인하는 프로그램
*********************/
#include <iostream>
#include <fstream>
#include <cstring>
#define MAXLEN 50+5
using namespace std;

/***************
param_ 
	arr : string(input line).
	arrsize : lenth of arr[]
	idx : current index of arr
	numOp: number of '(' unclosed. numOp becomes negative when ')' comes before '('

algorithm_(recursive)
	if every index of array is checked then
		there's no left symbol --> valid
		else -> invalid
	else if '(' comes before '(' then
		invalid
	else
		if arr[idx]=='(' then numOp+=1
		else numOp-=1
		checkThe next idx;
****************/
void checkParenthesis(char arr[MAXLEN], int arrsize, int idx, int numOp){
	if(idx==arrsize){
		cout << (numOp == 0 ? "YES" : "NO" ) << endl;	
		return;
	}
	else if(numOp<0){
		cout << "NO" << endl;
		return;
	}
	numOp += (arr[idx]=='(' ? 1 : -1);
	idx++;
	return checkParenthesis(arr, arrsize, idx, numOp);
}

int main(){
	ifstream f;
	f.open("input.txt", ifstream::in);
	int numcase;
	f >> numcase;
	for(int i=0; i<numcase; i++){
		char arr[MAXLEN];
		f >> arr;
		checkParenthesis(arr, strlen(arr), 0, 0);
	}

	return 0;
}