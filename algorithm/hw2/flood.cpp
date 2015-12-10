/*
20123434 Ȳ����

����_
�簢������ ������� � �ǹ��� ��鵵�� �־����� ��, �� �ǹ��� ���ο��� ������ �и��� ���� ���� ���� ũ�⸦ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
�� �ǹ��� ��鵵�� ���ڷ� �׷��� ������, ���� ���� ��+���� ǥ�õǾ� �ְ�, �簢�� �ǹ��� ���� �ٱ��� �׻� ������ �ѷ� �׿��� �ִ�. 
�� �ǹ����� ���̶� ������ �ѷ� �׿��� ������, ���� �Ʒ�/��, ����/���������� ����� �������� ������ ��Ÿ����.


�� �׽�Ʈ ���̽��� �ش��ϴ� ����� ù �ٿ� �ԷµǴ� �ǹ��� ��鵵�� ��Ÿ�� �ִ� ���� ������ ��Ÿ���� ������ ����Ѵ�. 
����� �� ��° �ٿ��� �ԷµǴ� �ǹ��� �� ���� ũ�⸦ ��Ÿ���� ������ ũ�Ⱑ ū ������ ���� ������� �� �ٿ� ����Ѵ�.

�˰���_
floodFill�˰���(�����)�� �̿�.
�� �˰����� �Ʒ��� floodFill()���� ���
*/

#include <iostream> //ǥ�� ��/��� ���� ���� ���
#include <fstream> //���� �Է��� ���� ���
#include <algorithm> // ������ ���� ���
#define MAXLEN (110)
using namespace std;


/*****
����� floodFill�˰����� �����ϴ� function.

parameter : 
	floodFill �˰����� �̿��� function.
	arr[][] : room ������ �ش��ϴ� array
	i, j : �˻��� room�� �ε���.
	colour : room�� ä�� colour.
	cnt : room[i][j]=='.'�̸� cnt�� ����������. call-by-reference�� �̿�����.

�˰��� : 
Flood-fill (node, target-color, replacement-color):
 1. If target-color is equal to replacement-color, return.
 2. If the color of node is not equal to target-color, return.
 3. Set the color of node to replacement-color.
 4. Perform Flood-fill (one step to the west of node, target-color, replacement-color).
    Perform Flood-fill (one step to the east of node, target-color, replacement-color).
    Perform Flood-fill (one step to the north of node, target-color, replacement-color).
    Perform Flood-fill (one step to the south of node, target-color, replacement-color).
 5. Return.
 <��ó : ��Ű�ǵ��>
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
floodFill function()����, room[idx1][idx2]�� �˻�� colour, cnt�� �����ϴ� �Լ�.

parameter : 
	arr[][] : room ������ �ش��ϴ� array
	int m, n : size of room. room�� n*mũ����.
******/
void check(char arr[MAXLEN][MAXLEN], int m, int n)
{
	char colour = 0; //initialize colour
	int cnt[MAXLEN] = {0}; //initialize count. ���� ������ 100���� ���� ����.
	for(int i=1; i<n; i++)
		for(int j=1; j<m; j++)
			if(arr[i][j]=='.')
				floodFill(arr, i, j, colour++, cnt[colour]); //check()���� floodFill�� ������ �� ���� colour���� ������.

	sort(cnt, cnt+int(colour+1)); //room�� ���簡 ���� ��, count���� sorting���ְ�
	cout << int(colour) << endl;
	for(int i=colour; i>0; i--) // �������� ���.
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