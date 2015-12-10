/*
20123434 황정담

문제 설명_
정수 n을 입력받아 n!을 재귀적으로 구하는 함수.

알고리즘_
n! = 1 if n==0 else n*(n-1)!
*/
#include <iostream>
#include <fstream>
using namespace std;

int factorial(int n){
	return n==0 ? 1 : n*factorial(n-1);
}


int main(){
	ifstream f;
	f.open("input.txt", ifstream::in );
	int numcase;
	f >> numcase;
	for(int i=0; i<numcase; i++){
		int testcase;
		f>>testcase;
		cout << factorial(testcase) << endl;
	}
	return 0;
}