/*
��Ŀ 1440: ���ű�2013����Ľ�����-������
ʱ������: 1Sec �ڴ�����: 128MB �ύ: 2183 ���: 1243
��Ŀ����
100  ���Ա�ʾΪ����������ʽ��100  =  3  +  69258  /  714��
�����Ա�ʾΪ��100  =  82  +  3546  /  197��
ע���������������У�����1~9�ֱ������ֻ����һ�Σ�������0����
���������Ĵ�������100  ��  11  �ֱ�ʾ����
����
�ӱ�׼�������һ��������N  (N< 1000*1000) 
���
�������������������1~9���ظ�����©����ɴ�������ʾ��ȫ�������� 
ע�⣺��Ҫ�����ÿ����ʾ��ֻͳ���ж��ٱ�ʾ���� 
��������
100  
�������
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
