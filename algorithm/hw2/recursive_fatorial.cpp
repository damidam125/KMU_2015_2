/*
20123434 Ȳ����

���� ����_
���� n�� �Է¹޾� n!�� ��������� ���ϴ� �Լ�.

�˰���_
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