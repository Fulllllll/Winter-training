/*[�ݹ�]ĸţ�Ĺ���
��Ŀ����
��һͷĸţ����ÿ�������һͷСĸţ��ÿͷСĸţ�ӵ��ĸ���ͷ��ʼ��ÿ�����Ҳ��һͷСĸţ������ʵ���ڵ�n���ʱ�򣬹��ж���ͷĸţ��

����
���������ɶ������ʵ����ɣ�ÿ������ʵ��ռһ�У�����һ������n(0<n<55)��n�ĺ�������Ŀ��������
n=0��ʾ�������ݵĽ�������������

���
����ÿ������ʵ��������ڵ�n���ʱ��ĸţ��������
ÿ�����ռһ�С�

��������
2
4
5
0
�������
2
4
6*/

//���Ʒ�
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
	while (cin>>n && n)     //cin �Ķ��������ʽ  
							//�Լ����� 0 ʱ��ֹͣ����  
	{
		func();
		cout << ans << endl;
	}
	return 0;
}

//�ݹ鷨
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
