/*
20123434 황정담

문제_
사각형으로 만들어진 어떤 건물의 평면도가 주어졌을 때, 이 건물의 내부에서 벽으로 분리된 여러 개의 방의 크기를 계산하는 프로그램을 작성하시오. 
이 건물의 평면도는 문자로 그려져 있으며, 벽은 문자 ‘+’로 표시되어 있고, 사각형 건물의 가장 바깥은 항상 벽으로 둘러 쌓여져 있다. 
이 건물에서 방이란 벽으로 둘러 쌓여져 있으며, 서로 아래/위, 왼쪽/오른쪽으로 연결된 연속적인 공간을 나타낸다.


각 테스트 케이스에 해당하는 출력의 첫 줄에 입력되는 건물의 평면도에 나타나 있는 방의 개수를 나타내는 정수를 출력한다. 
출력의 두 번째 줄에는 입력되는 건물의 각 방의 크기를 나타내는 정수를 크기가 큰 수에서 작은 순서대로 한 줄에 출력한다.

알고리즘_
floodFill알고리즘(재귀적)을 이용.
상세 알고리즘은 아래의 floodFill()에서 기술
*/

#include <iostream> //표준 입/출력 등을 위한 헤더
#include <fstream> //파일 입력을 위한 헤더
#include <algorithm> // 소팅을 위한 헤더
#define MAXLEN (110)
using namespace std;


/*****
재귀적 floodFill알고리즘을 실행하는 function.

parameter : 
	floodFill 알고리즘을 이용한 function.
	arr[][] : room 정보에 해당하는 array
	i, j : 검사할 room의 인덱스.
	colour : room을 채울 colour.
	cnt : room[i][j]=='.'이면 cnt를 증가시켜줌. call-by-reference를 이용했음.

알고리즘 : 
Flood-fill (node, target-color, replacement-color):
 1. If target-color is equal to replacement-color, return.
 2. If the color of node is not equal to target-color, return.
 3. Set the color of node to replacement-color.
 4. Perform Flood-fill (one step to the west of node, target-color, replacement-color).
    Perform Flood-fill (one step to the east of node, target-color, replacement-color).
    Perform Flood-fill (one step to the north of node, target-color, replacement-color).
    Perform Flood-fill (one step to the south of node, target-color, replacement-color).
 5. Return.
 <출처 : 위키피디아>
******/
void floodFill(char arr[MAXLEN][MAXLEN], int i, int j, char colour, int& cnt)
{
	if(arr[i][j]=='.')
	{
		arr[i][j] = colour;
		cnt++;
	
	floodFill(arr, i-1, j, colour, cnt);
	floodFill(arr, i, j-1, colour, cnt);
	floodFill(arr, i, j+1, colour, cnt);
	floodFill(arr, i+1, j, colour, cnt);
	}
}



/*****
floodFill function()전에, room[idx1][idx2]의 검사와 colour, cnt를 관리하는 함수.

parameter : 
	arr[][] : room 정보에 해당하는 array
	int m, n : size of room. room은 n*m크기임.
******/
void check(char arr[MAXLEN][MAXLEN], int m, int n)
{
	char colour = 0; //initialize colour
	int cnt[MAXLEN] = {0}; //initialize count. 방의 갯수는 100개를 넘지 않음.
	for(int i=1; i<n; i++)
		for(int j=1; j<m; j++)
			if(arr[i][j]=='.')
				floodFill(arr, i, j, colour++, cnt[colour]); //check()에서 floodFill을 실행할 때 마다 colour값이 증가함.

	sort(cnt, cnt+int(colour+1)); //room의 조사가 끝난 후, count값을 sorting해주고
	cout << int(colour) << endl;
	for(int i=colour; i>0; i--) // 역순으로 출력.
		cout << cnt[i] << ' ';
	cout << endl;
}

int main(){
	ifstream f;
	f.open("input.txt", ifstream::in );
	int numcase;
	f >> numcase;
	for(int i=0; i<numcase; i++){
		int m, n;
		f >> m >> n;
		char room[MAXLEN][MAXLEN];
		for(int i=0; i<n; i++)
			f >> room[i];

		check(room, m, n);
	}
	return 0;
}