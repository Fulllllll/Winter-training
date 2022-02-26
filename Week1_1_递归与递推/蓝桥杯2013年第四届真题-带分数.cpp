/*
题目 1440: 蓝桥杯2013年第四届真题-带分数
时间限制: 1Sec 内存限制: 128MB 提交: 2183 解决: 1243
题目描述
100  可以表示为带分数的形式：100  =  3  +  69258  /  714。
还可以表示为：100  =  82  +  3546  /  197。
注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。
类似这样的带分数，100  有  11  种表示法。
输入
从标准输入读入一个正整数N  (N< 1000*1000) 
输出
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。 
注意：不要求输出每个表示，只统计有多少表示法！ 
样例输入
100  
样例输出
11

*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int f[11];
int n, ans;

void check()
{
	int num = 0;
	int num1, num2;
	for (int i = 1; i <= 7; i++)
	{
		num = num * 10 + f[i];
		if (num > n) return;
		num1 = num2 = 0;
		for (int j = i + 1; j < 9; j++)
		{
			num1 = num1 * 10 + f[j];
			num2 = 0;
			for (int k = j + 1; k <= 9; k++) 
				num2 = num2 * 10 + f[k];

			if (num1 % num2 == 0)
			{
				if (num + num1 / num2 == n) ans++;
			}
		}
	}
}
int main()
{
	while (~scanf("%d", &n))
	{
		ans = 0;
		for (int i = 1; i <= 9; i++) f[i] = i;
		do {
			check();
		} while (next_permutation(f + 1, f + 1 + 9));
		cout << ans << endl;
	}
	return 0;
}
