/********************
20123434 Ȳ����
card game
********************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

inline int max(int a, int b) {
	return a > b ? a : b;
}

int table[1001][1001];
int card[1001], sum_card[1001];

int calc_score(int s, int e)
{
	if (s > e) 
		return 0;
	if (s == e)
		return card[s]; 
	if (table[s][e] >= 0) return table[s][e];
	table[s][e] = max(sum_card[e] - sum_card[s - 1] - calc_score(s + 1, e), sum_card[e] - sum_card[s - 1] - calc_score(s, e - 1));
	return table[s][e];
}


int main()
{
	freopen("input.txt", "r", stdin);
	int num_case;
	int num_card;
	cin >> num_case;

	for (int i = 0; i < num_case; ++i)
	{
		cin >> num_card;
		memset(table, 0, sizeof(table));
		memset(sum_card, 0, sizeof(sum_card));
		for (int j = 0; j < num_card; ++j)
			scanf("%d", card + j);
		for (int j = 0; j < num_card; ++j)
			sum_card[j] = sum_card[j-1]+card[j];
		for (int j = 0; j < num_card; ++j)
		for (int k = 0; k < num_card; ++k)
			table[j][k] = -1;
		cout << calc_score(0, num_card - 1)<<endl;
	}
}
