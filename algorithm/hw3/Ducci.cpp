/*********************
20123434 È²Á¤´ã
Problem E - Ducci Sequence

basics:
ducci sequence : (a1, a2, ..., an) -> (|a1-a2|, |a2-a3|, ..., |an-a1|)
ducci sequence either reach a tuple of zeros of fall into a periodic loop.
*********************/
#include <iostream>
#include <fstream>
#define MAXLEN 1000
using namespace std;

//abs(a,b) returns |a-b|
int abs(int a, int b){
	return a>b ? (a-b) : (b-a);
}

//if all element of arr is zero returns true, else return 1
int allElemZero(int arr[MAXLEN], int size){
	for(int i=0; i<size; i++)
		if(arr[i]!=0)
			return 0;
	return 1;
}

/*****************
function for check given size-tuple integers falls into ZERO/LOOP ducci sequence

algorithm_
doing ducci for 1000 times:
	checks arr becomes ZERO --> then print ZERO and return;
if there's no ZERO ducci, then print LOOP and return.
*****************/
void DucciSequence(int arr[MAXLEN], int size, int cnt){
	if(cnt == MAXLEN){
		cout << "LOOP" << endl;
		return;
	}
	else if(allElemZero(arr, size)==1){
		cout << "ZERO" << endl;
		return;
	}

	int* temp = new int[size];
	for(int i=0; i<size-1; i++)
		temp[i] = abs(arr[i], arr[i+1]);
	temp[size-1] = abs(arr[size-1], arr[0]);
	for(int i=0; i<size; i++)
		arr[i] = temp[i];
	delete[] temp;
	return DucciSequence(arr, size, cnt+1);
}

int main(){
	ifstream f;
	f.open("input.txt", ifstream::in);
	int numcase;
	f >> numcase;
	for(int i=0; i<numcase; i++){
		int arr[MAXLEN];
		int size;
		f >> size;
		for(int j=0; j<size; j++)
			f >> arr[j];
		DucciSequence(arr, size, 0);
	}

	return 0;
}