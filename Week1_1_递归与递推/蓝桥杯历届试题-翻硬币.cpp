/*
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
using namespace std;
string s1, s2;
int len, ans;

void reverse(int i)
{
	if (s1[i] == '*') s1[i] = 'o';
	else s1[i] = '*';
}

int main()
{
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size() - 1; i++)
	{
		if (s1[i] != s2[i])
		{
			reverse(i);
			reverse(i + 1);
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
