/********************
20123434 Ȳ����
������
********************/
#include <stdlib.h>
#include <stdio.h>

struct Cor{
	int x,y;
};


int pivotX(const void*a, const void*b){
	int n = (*(struct Cor*)a).x - (*(struct Cor*)b).x;
	if (n!=0)
		return n;
	else
		return (*(struct Cor*)a).y - (*(struct Cor*)b).y;
}

int pivotY(const void*a, const void*b){
	return (*(struct Cor*)b).y - (*(struct Cor*)a).y;
}

int main(){
	FILE* fp;
	struct Cor cor[100010];
	int numcase;

	fp=fopen("input.txt", "r");
	fscanf(fp, "%d", &numcase);
	while(numcase--){
		int numCor;
		int cnt=1;
		int i,j;
		int numorder, order;

		fscanf(fp, "%d", &numCor);
		for(i=0; i<numCor; i++)
			fscanf(fp, "%d %d", &cor[i].x, &cor[i].y);

		qsort(cor, numCor, sizeof(struct Cor), pivotX);

		for(i=0, cnt=1; i<numCor-1; cnt=1){
			if(cor[i].x!=cor[i+1].x){
				i++;
				continue;
			}
			
			//when x is equal
			for(j=i; (cor[j].x==cor[j+1].x) && j<numCor-1; j++)
				cnt++;
			if(i==0 && cor[i].y!=0)
				qsort(cor+i, cnt, sizeof(struct Cor), pivotY);
			if(i!=0 && (cor[i-1].y!=cor[i].y))
				qsort(cor+i, cnt, sizeof(struct Cor), pivotY);
			i+=cnt;
		}
		fscanf(fp, "%d", &numorder);
		for(i=0; i<numorder; i++){
			fscanf(fp, "%d", &order);
			printf("%d %d\n", cor[order-1].x, cor[order-1].y);
		}

	}

}
