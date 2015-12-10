//20123434 Ȳ����
//two numbers :
//
//problem_
//given a set of distinct integers s = {a1, a2, ...., an}, and a given target number k,
//your task is to find two different numbers of s which add up nearest to k.
//
//algorithm_twonumbers...�� �������ϰڴ�
//*********************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
int find_K(int arr[], int k, int begin, int end);
int b_search(int arr[], int num, int begin, int end, int origin);

int cmp(const void* a, const void* b){
	return *(int*)a - *(int *)b;
}

int min_cha;

int main()
{
	int num_case;
	ifstream infile;
	infile.open("input.txt");
	infile >> num_case;

	for (int i = 0; i < num_case; ++i)	{
		int n, t, num, xy;
		int bound;
		int* myarr;
		int k, cnt = 0;

		infile >> n >> t;
		myarr = new int[n];
		min_cha = 0;

		for (int j = 0; j < n; ++j) {
			infile >> myarr[j];
			if (t < 0)
				myarr[j] = -myarr[j];
		}
		t = t < 0 ? -t : t;
		qsort(myarr, n, sizeof(int), cmp);

		min_cha = abs(t - (myarr[0] + myarr[1]));
		cnt = find_K(myarr, t, 0, n);
		if (cnt == 0)
			cnt += find_K(myarr, t + min_cha, 0, n) + find_K(myarr, t - min_cha, 0, n);
		cout << cnt << endl;
	}
}

int find_K(int* arr, int t, int begin, int end)
{
	int bound = t;
	int k;
	int find_idx;

	int cnt = 0;
	for (int i = 0; i < end && arr[i] < bound; ++i)
	{
		k = t - arr[i];
		find_idx = b_search(arr, k, begin, end, arr[i]);
		if (find_idx != -1 && k != arr[i])
		{
			cnt++;
			bound = k;
		}
	}
	return cnt;
}

//K=20�϶� arr[i]=3�̾����� origin=3, num=17. ã�°Ծ����� �ִ��� ����� ���� idx�� ã��
int b_search(int arr[], int num, int begin, int end, int origin)
{
	int l = begin, r = end, mid;
	int idx = -1;
	int cha;

	while (l <= r) //binary search_basic
	{
		mid = (l + r) / 2;
		if (arr[mid] > num)
			r = mid - 1;
		else if (arr[mid] < num)
			l = mid + 1;
		else
			return mid;
	}

	//missing value <num>
	if (mid <= begin) {//check side-left
		mid = begin;
		idx = mid;

		cha = abs(arr[begin] - num);
		if (cha > abs(arr[mid + 1] - num)) {
			cha = abs(arr[mid + 1] - num);
			idx = mid + 1;
		}
	}
	else if (mid >= end - 1) {//check side-right
		mid = end - 1;
		idx = mid;
		cha = abs(arr[end - 1] - num);
		if (cha > abs(arr[mid - 1] - num)) {
			cha = abs(arr[mid - 1] - num);
			idx = mid - 1;
		}
	}
	else {//middle
		cha = abs(arr[mid] - num);
		idx = mid;
		if (cha > abs(arr[mid - 1] - num)) {
			cha = abs(arr[mid - 1] - num);
			idx = mid - 1;
		}
		if (cha > abs(arr[mid + 1] - num)) {
			cha = abs(arr[mid + 1] - num);
			idx = mid + 1;
		}
	}

	if (cha < min_cha && origin != arr[idx])
		min_cha = cha;
	return -1;
}