/****************
20123434 Ȳ����
knightTour_

algorithm_recursive)
process knightTour
begin
if given x,y coordinate are not in the boundary then
	return 0;
if given board(x,y) is already marked then
	return 0;

mark board(x,y), increment count
if board is fullyMarked then
	return 1;

for i in possibleMoves:
	flag = knightTour(coord(x,y)+i)
	if flag ==1 then
		return 1;
unmark board(x,y), decrement count
return 0;
****************/


#include <iostream>
#include <fstream>
#define MAX 8
using namespace std;

struct coord{
	int x, y;
	void set(int a, int b) { x = a, y = b; }
};

coord chessMove[8] = { {-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1} };

int knightTour(int board[MAX][MAX], int m, int n, coord cor, int& order){
	if( cor.x<0 || cor.x >= m || cor.y<0 || cor.y >= n )
		return 0;
	else if( board[cor.x][cor.y]!=0 )
		return 0;
	board[cor.x][cor.y] = order++;
	if(order==m*n+1)
		return 1;

	for(int i=0; i<8; i++){
		coord temp; temp.set(cor.x+chessMove[i].x, cor.y+chessMove[i].y);
		int flag = knightTour(board, m, n, temp, order);
		if(flag==1)
			return 1;
	}
	board[cor.x][cor.y] = 0; --order;
	return 0;
}

int main(){
	ifstream fp;
	fp.open("input.txt");
	int numTest;
	fp >> numTest;

	while(numTest--){
		int m, n;
		int board[MAX][MAX] = {0};
		int order = 1;
		fp >> m >> n;
		coord start;
		fp >> start.x >> start.y;
		start.x--; start.y--;

		int flag = knightTour(board, m, n, start, order);
		cout << flag << endl;
		if(flag!=0){
			for(int i=0; i<m; i++){
				for(int j=0; j<n; j++)
					cout << board[i][j] << " ";
				cout << endl;
			}
		}
	}
	fp.close();
}