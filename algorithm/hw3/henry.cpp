/*********************
20123434 황정담
henry : 
basic : all fractions can be represented by a sum of distinct unit fractions.
theme :
	procedure will result in a series of unit fractions 1/x1, 1/x2, 1/x3.... that sum up to the given fraction a/b
	where 1/x1<=a/b. and 1/x2 <= a/b-1/x1 ....
	1/xn <= a/b - sum(1/x1 +... + 1/xn-1)
*********************/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

/*************
유클리트 호제법을 이용해 최대공약수를 구하는 함수
param : 
	a : 분자
	b : 분모
*************/
unsigned int gcd(unsigned int a, unsigned int b){
	return b==0 ? a: gcd(b, a%b);
}


/***************
param : 
	numer1 : a/b에서의 a. 분자
	deno1 :  a/b에서의 b. 분모
	deno2 : 1/xn에서의 xn. 분모
	
***since it's hard to compare float numbers, i transformed comparison of floats to comparsion of integer
	ex _ 1/x1 == a/b equal to b == a*x1.
algorithm:
	if a/b==1/xm ( a*xm == b) then
		print xm and return
	
	if a/b - sum(1/x1 +... + 1/xn-1) < 1/xm then
		return henry(a, b, xm+1)
	else
		return henry(a*xm-b, b*xm, xm+1)
***************/
void henry(unsigned int numer1, unsigned int deno1, unsigned int deno2){
	unsigned int eur = gcd(numer1, deno1);
	numer1 /= eur;	deno1 /= eur;
	if(numer1*deno2==deno1 || numer1==0){
		cout << (deno2==2 ? deno2 : deno2-1) << endl;
		return ;
	}

	while(numer1*deno2<deno1)
		deno2++;
	return henry(numer1*deno2-deno1, deno1*deno2, deno2+1);
}


int main(void){
	ifstream fp;
	fp.open("input.txt", ifstream::in);
	int numcase;
	fp >> numcase;
	for(int i=0; i<numcase; i++){
		unsigned int num1, num2;
		fp >> num1 >> num2;
		henry(num1, num2, 2);
	}
	return 0;
}