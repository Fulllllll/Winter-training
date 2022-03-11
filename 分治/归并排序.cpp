#include<bits/stdc++.h>
 


void Merge(int c[], int d[], int l, int m, int r);  
//主要函数 将 c数组中的两部分合并到 d数组中 

void MergeSort1(int a[], int l, int r);		//递归 
void copy(int a[], int b[], int l, int r);	 //将数组 b中的内容copy到数组 a中 


void MergeSort2(int a[], int n);		//非递归 
void mergepass(int x[], int y[], int s, int n);



int b[100] = { 0 };
int main()
{
	int a[100] = { 6,5,4,3,2,1,7,8,9,0,11,10 }; //12个元素
	//MergeSort1(a, 0, 11);
	MergeSort2(a, 12);
	for (int i = 0; i < 12; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}






void Merge(int c[], int d[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	
	while ((i <= m) && (j <= r))
	{
		if (c[i] <= c[j])
			d[k++] = c[i++];
		else
			d[k++] = c[j++];
	}
	if (i > m)
	{
		for (int q = j; q <= r; q++)
			d[k++] = c[q];
	}
	else
	{
		for (int q = i; q <= m; q++)
			d[k++] = c[q];
	}
}

void mergepass(int x[], int y[], int s, int n)
{
	int i = 0;
	while (i <= n - 2 * s)
	{
		Merge(x, y, i, i + s - 1, i + 2 * s - 1);
		i += 2 * s;
	}
	if (i + s < n)
	{
		Merge(x, y, i, i + s - 1, n - 1);
	}
	else
	{
		for (int j = i; j <= n - 1; j++)
		{
			y[j] = x[j];
		}
	}
}

void MergeSort1(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort1(a, l, m);
		MergeSort1(a, m + 1, r);
		Merge(a, b, l, m, r);  
		copy(a, b, l, r);
	}
}
void MergeSort2(int a[], int n)
{
	int s = 1;
	while (s < n)
	{
		mergepass(a, b, s, n);
		s += s;
		mergepass(b, a, s, n);
		s += s;
	}
}

void copy(int a[], int b[], int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		a[i] = b[i];
	}
}
