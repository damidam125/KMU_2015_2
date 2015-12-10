/************
20123434 Ȳ����
file_merge
*************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAXSIZE 502
#define INF 987654321
using namespace std;
int m_file[MAXSIZE][MAXSIZE];
int chapter[MAXSIZE];

int merge_file(int end)
{
	int p, q, r, min;
	for (p = 2; p <= end; ++p)
	for (q = p - 1, min = INF; q >= 1; --q)
	{
		for (r = p - 1; r >= q; --r)
		if (min > m_file[q][r] + m_file[r + 1][p])
			min = m_file[q][r] + m_file[r + 1][p];
		m_file[q][p] = min += chapter[p] - chapter[q - 1];
	}

	return m_file[1][end];
}

int main()
{
	int num_case, num_file, f_size;
	freopen("input.txt", "r", stdin);
	cin >> num_case;
	for (int i = 0; i < num_case; ++i)
	{
		scanf("%d", &num_file);
		for (int j = 1; j <= num_file; ++j)
		{
			scanf("%d", &f_size);
			chapter[j] = chapter[j - 1] + f_size;
		}

		printf("%d\n", merge_file(num_file));
	}
}