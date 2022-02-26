#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n, c;

bool check(int mid)
{		
	int cnt = 0;
	int last = 0;
	a[0] = 0 - mid;
	for(int i = 1; i <= n; i++)
	{
		if (a[i] - a[last] >= mid)
		{
			last = i;
			cnt++;
		}
	}
	if (cnt >= c) return 1;
	else return 0;
}

int main() {
	
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int left = 1;
	int right = a[n] - a[1];
	int mid;
	
	while (left < right) {
		mid = (right + left + 1) / 2;
		if (check(mid)) {
			left = mid ;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << endl;
	return 0;
}
