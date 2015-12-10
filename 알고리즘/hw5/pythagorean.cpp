/*************
20123434 Ȳ����
pythagoreadn expectation
*************/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
inline int pow2(int a){ return a*a; }

int record[1000][2] = {0};
int result[1000] = {0};
int main(){
	ifstream fp;
	fp.exceptions(ifstream::failbit);
	try{
		fp.open("input.txt", ifstream::in);
	}
	catch(ifstream::failure& e){
		cerr << e.what() << endl;
	}
	int numCase;
	if( !fp.eof() ) fp >> numCase;
	while( numCase-- ){
		int n, m;
		fp >> n >> m;
		for(int i=0; i<m; i++){
			int a,b,p,q;
			fp >> a >> b >> p >> q;
			record[a-1][0] += p;
			record[a-1][1] += q;		
			record[b-1][0] += q;
			record[b-1][1] += p;
		}
		for(int i=0; i<n; i++){
			if(record[i][0]==0)
				result[i] = 0;
			else 
				result[i] = 1000*pow2(record[i][0]) / ( pow2(record[i][0]) + pow2(record[i][1]));
		}
		sort(result, result+n);
		cout << result[n-1] << endl << result[0] << endl;
		for(int i=0; i<n; i++)
			record[i][0] = record[i][1] = 0;
	}
}