/***********
20123434 Ȳ����
palindrom
***********/
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	ifstream fp;
	fp.open("input.txt", ifstream::in);
	int num_case;

	fp >> num_case;
	for (int i = 0; i < num_case; ++i)
	{
		int inputNum;
		int temp, res;
		int ispal = 0;

		fp >> inputNum;

		for (int B = 2; B <= 64 && ispal == 0; ++B)
		{
			char arr[1000];
			int cnt = 0;
			temp = inputNum;
			//convert to n-base 2<=n<=64
			while (temp != 0)
			{
				res = temp%B;
				temp = temp / B;
				arr[cnt++] = res ;
			}

			//check palindrome
			ispal = 1;
			for(int left=0, right=cnt-1; left<=right; left++, right--)
				if (arr[left] != arr[right]) {
					ispal=0; break;
				}
		}

		if (ispal == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
}
