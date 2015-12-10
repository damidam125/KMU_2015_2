/***********
20123434 È²Á¤´ã
sudoku
***********/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

#define BOXSIZE (3)
#define SIZE (BOXSIZE*BOXSIZE)

#define NODES_HEIGHT (SIZE+1) // size+1(header)
#define NODES_WIDTH (4*SIZE*SIZE) /* each N for candidate, row, col, box*/
using namespace std;

#define NUMCAST (4)

/*
	Node for dancing link
*/
class Node{
public:
	union{
		char size;
		unsigned int name;
	};
	Node *up, *down, *left, *right;
	Node *column;

	void nameCell(unsigned int row, unsigned int col, unsigned int cand) {
		name = ( (row<<16) | (col<<8) | (cand)); 
	}
};

class DancingSudoku{
public:
	unsigned int result[SIZE*SIZE];
	Node h;
	Node nodes[NODES_HEIGHT*NODES_WIDTH];
	Node *rows[SIZE*SIZE*SIZE];

	DancingSudoku();
	void printResult();
	int parse_grid(ifstream &fp);
	int search(int k);
private:
	const static int CAST_CAND  = 0;
	const static int CAST_ROW = 1;
	const static int CAST_COL = 2; 
	const static int CAST_BOX = 3;	
	void init()	//set all value with 0
	{
		memset(result, 0, sizeof(unsigned int)*SIZE*SIZE);
		memset(&h, 0, sizeof(Node));
		memset(nodes, 0, sizeof(Node)*NODES_HEIGHT*NODES_WIDTH);
		memset(rows, 0, sizeof(Node*));	
	}
	int getNodePos(const int type, const int row, const int col, const int num) // for detail explanation, see the picture
	{
		switch(type){
		case CAST_CAND : return col + row*SIZE;
		case CAST_ROW  : return num + row*SIZE;
		case CAST_COL : return num + col*SIZE;
		case CAST_BOX : return num + col/BOXSIZE*SIZE + row/BOXSIZE*BOXSIZE*SIZE;
		}
	}
	void linkHeader();
	void linkVertical();
	void linkHorizontal();
	void cover(Node *cN);
	void recover(Node *rN);
	Node* selectCol();
};

DancingSudoku :: DancingSudoku() {
	init();
	linkHeader();
	linkVertical();
	linkHorizontal();
}

void DancingSudoku :: linkVertical(){
	Node *temp = nodes;
	for(int j=0; j<NODES_HEIGHT; j++){
		for(int i=0; i<NODES_WIDTH; i++, temp++){
			temp->up = (j==0 ? &(nodes[ (NODES_HEIGHT-1)*NODES_WIDTH+i]) : temp-NODES_WIDTH);
			temp->down = (j==NODES_HEIGHT-1? nodes+i : temp+NODES_WIDTH);
			temp->column = nodes+i;
		}
	}
}
void DancingSudoku :: linkHorizontal(){
	Node *temp = nodes;
	Node *rowNodes[NUMCAST];
	//link horizontal
	for(unsigned int r=0, i=0; r<SIZE; r++){
		for(unsigned int c=0; c<SIZE; c++){
			for(unsigned int cand=0; cand<SIZE; cand++){

				for(int type=0; type<NUMCAST; type++){
					int pos = getNodePos(type, r, c, cand);
					Node *colHead = &(nodes[type*SIZE*SIZE+pos]);

					temp = colHead->down + NODES_WIDTH * colHead->size++;
					temp-> nameCell(r,c,cand+'1');
					rowNodes[type] = temp;
				}

				for(int type=0; type<NUMCAST; type++){
					rowNodes[type]->left = rowNodes[ type==0 ? NUMCAST-1 : type-1 ];
					rowNodes[type]->right = rowNodes[ type==NUMCAST-1 ? 0 : type+1 ];
				}
				rows[i++] = rowNodes[0];
			}
		}
	}
}
void DancingSudoku :: linkHeader(){
	h.right = nodes;
	h.left = nodes+NODES_WIDTH -1;
	for(int i=0; i<NODES_WIDTH; i++){
		nodes[i].left = (i==0 ? &h : nodes+i-1);
		nodes[i].right = (i==NODES_WIDTH-1 ? &h : nodes+i+1 );
	}
}

void DancingSudoku :: cover(Node *cN) // cN : node to cover. in knuth's paper
{
	Node *i, *j;
	cN->right->left = cN->left;
	cN->left->right = cN->right;
	for(i=cN->down ; i!=cN; i=i->down){
		for(j=i->right; j!=i; j=j->right){
			j->down->up = j->up;
			j->up->down = j->down;
			j->column->size--;
		}
	}
}

void DancingSudoku :: recover(Node *rN){ //rN : node to recover. in knuth's paper
	Node *i, *j;
	for(i=rN->up; i!=rN; i=i->up){
		for(j=i->left; j!=i; j=j->left){
			j->column->size++;
			j->down->up = j->up->down = j;
		}
	}
	rN->right->left = rN->left->right= rN;
}

void DancingSudoku :: printResult()
{
	char grid[SIZE*SIZE] = {0};

	for(int i=0; i<SIZE*SIZE; i++){
		char row = result[i] >> 16&0xff;
		char col = result[i] >> 8&0xff;
		char num = result[i]&0xff;
		grid[row*SIZE + col] = num;
	}

	char *p = grid;
	for(int j=0; j<SIZE; j++){
		for(int i=0; i<SIZE; i++, p++){
			cout << (*p ? *p : '?' ) << " ";
		}
		if( j+1!=SIZE && (j+1)%SIZE==0 )
			cout << endl;
		cout << endl;
	}
}

Node* DancingSudoku ::  selectCol()
{
	Node *col =  h.right;
	Node *j;
	int size = 300000;

	if(col==&h)
		return NULL;
	for(j=h.right; j!=&h; j=j->right){
		if(j->size < size){
			col = j;
			size =  j->size;
		}
	}
	return col;
}

int DancingSudoku ::  search(int k)
{
	Node *r, *c, *j;
	//1. select col to cover
	c = selectCol();

	//2. cover the colum
	if(c==NULL){
		printResult();
		return 1;
	}
	cover(c);

	//3. use dancing link algorithm
	for(r=c->down; r!=c; r=r->down){
		result[k] = r->name;
		for(j=r->right; j!=r; j=j->right)
			cover(j->column);
		if(search(k+1))
			return 1; 

		result[k] = 0;
		for(j=r->left; j!=r; j=j->left)
			recover(j->column);
	}
	recover(c);
	return 0;
}


int DancingSudoku ::  parse_grid(ifstream &fp){
	char buf[10];
	int k=0;

	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++)
			fp >> buf[j];

		for(int j=0; j<SIZE; j++){
			if('1'<=buf[j] && buf[j]<'1'+SIZE){
				Node *x;
				Node *r = rows[i*SIZE*SIZE + j*SIZE + buf[j] - '1'];
				result[k++] = (i<<16 | j<<8 | buf[j]);
				cover(r->column);
				for(x=r->right; x!=r; x=x->right)
					cover(x->column);
			}
		}
	}
	return k;
}


int main()
{
	ifstream fp;
	fp.open("input.txt", ifstream::in);	
	unsigned int numcase;
	fp >> numcase;
	while(numcase--){
		DancingSudoku DS; //get Sudoku board. initialize the board with all possible links
		unsigned int k = DS.parse_grid(fp); //set board with given input
		DS.search(k); //do search
	}
}