#include<bits/stdc++.h>
using namespace std;

int Partition(int a[], int p, int r, int x);	//�Զ��� ���ֺ���
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
		sort(&a[p], &a[r]);  //��ģ��С��ֱ�ӷ��أ�ʱ�临�Ӷ�Ϊ����
		return a[p + k - 1];
	}
	int n = r - p + 1;
	for (int i = 0; i < n / 5; i++)    //ÿ����Ԫ�أ��ɷ�n/5��(��ϸ�����һ��)
	{
		sort(&a[p+5*i], &a[p + 5 * i + 4]);//��ÿ�������� a[p + 5 * i + 2] ��Ϊÿ����λ��
		Swap(a[i], a[p + 5 * i + 2]);				//�� ��λ���� �������У�
	}
	int x = Select(a, p, p + (n / 5 - 1), (n - 5) / 10);		//�ҳ���λ���ǵ���λ������Ϊ�Ǹ����ʵĻ�����
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
