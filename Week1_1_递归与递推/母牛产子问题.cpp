/*[递归]母牛的故事
题目描述
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？

输入
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。

输出
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。

样例输入
2
4
5
0
样例输出
2
4
6*/

//递推法
#include<bits/stdc++.h>
using namespace std;

int n, ans;

void func()
{
	int a[4] = { 0 };
	a[3] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		a[3] += a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = a[3];
	}
	ans = a[0] + a[1] + a[2] + a[3] ;
}

int main()
{
	while (cin>>n && n)     //cin 的多组输入格式  
							//以及输入 0 时，停止输入  
	{
		func();
		cout << ans << endl;
	}
	return 0;
}

//递归法
#include<bits/stdc++.h>
using namespace std;

int n, year[55] = { 0,1,2,3,4 };

int main()
{
	for (int i = 5; i < 55; i++)
	{
		year[i] = year[i - 1] + year[i - 3];
	}
	while (cin >> n && n)
	{
		cout << year[n] << endl;
	}
	return 0;
}
