#include<bits/stdc++.h>
using namespace std;

int Partition(int a[], int p, int r, int x);	//自定义 划分函数
int Select(int a[], int p, int r, int k);

template <class T>
void Swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}


int Partition(int a[], int p, int r, int x)
{
	int i = p - 1, j = r + 1;

	while (true)
	{
		while (a[++i] < x && i < j);
		while (a[--j] > x && i < j);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	return j;
}

int Select(int a[], int p, int r, int k)
{
	if ((r - p) < 75)
	{
		sort(&a[p], &a[r]);  //规模较小，直接返回，时间复杂度为常数
		return a[p + k - 1];
	}
	int n = r - p + 1;
	for (int i = 0; i < n / 5; i++)    //每组五元素，可分n/5组(不细分最后一组)
	{
		sort(&a[p+5*i], &a[p + 5 * i + 4]);//将每组排序，则 a[p + 5 * i + 2] 则为每组中位数
		Swap(a[i], a[p + 5 * i + 2]);				//将 中位数们 相邻排列，
	}
	int x = Select(a, p, p + (n / 5 - 1), (n - 5) / 10);		//找出中位数们的中位数，即为那个合适的划分数
	int i = Partition(a, p, r, x);
	int j = i - p + 1;

	if (k <= j)
		return Select(a, p, i, k);
	else
		return Select(a, i + 1, r, k - j);
}
int main()
{
	int a[105] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << Select(a, 0, 99, i + 1) << endl;
	}
	return 0;
}
