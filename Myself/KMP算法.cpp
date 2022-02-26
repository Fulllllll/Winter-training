#include <iostream>
#include <string>
using namespace std;

int* get_next(string& s);
int* get_nextval(string& s);
int KMP(string& a, string& b);
int my_KMP(string& a, string& b);


void print_next(string& s);
void print_nextval(string& s);

int main()
{
	//string a = "abcdedabcabd";
	//string b = "abcabd";

	string a = "ababababcababababc";
	string b = "abc"; 
	print_next(b);
	print_nextval(b);
	cout << KMP(a, b) << endl;
	return 0;
}
int KMP(string& a, string& b){
	int i, j, al = a.length(), bl = b.length();
	int* nextval = get_nextval(b);
	for (i = 0, j = 0; i < al; i++, j++)
	{
		if (j == bl)
		{
			delete[] nextval;
			return i - j;
		}
		while (j != -1 && a[i] != b[j])
			j = nextval[j];
	}
	delete[] nextval;
	return -1;
}
int my_KMP(string& a, string& b) {
	int al = a.length(), bl = b.length();
	int i = 0, j = 0;
	int* nextval = get_nextval(b);
	while (i < al)
	{
		if (a[i] == b[j])
		{
			if (j == bl - 1)
			{
				delete[] nextval;
				return i - bl + 1;
			}
				
			i++; j++;
		}
		else
		{
			if (nextval[j] == -1)
			{
				i++;
				j = 0;
			}
			else
			{
				j = nextval[j];
			}
		}
	}
	delete[] nextval;
	return -1;
}

int* get_next(string& s)
{
	int k = 0, n = s.length();
	int* next = new int[n];
	next[0] = -1;
	for (int i = 1; i < n; i++)
	{
		next[i] = k;
		while (k != -1 && s[i] != s[k])
			k = next[k];
		k++;
	}
	return next;
}

int* get_nextval(string& s)
{
	int k = 0, n = s.length();
	int* nextval = new int[n];
	nextval[0] = -1;
	for (int i = 1; i < n; i++)
	{
		nextval[i] = k;
		if (s[i] == s[k])
			nextval[i] = nextval[k];
		while (k != -1 && s[i] != s[k])
			k = nextval[k];
		k++;
	}
	return nextval;
}

void print_next(string& s)
{
	int n = s.length();
	int* next = get_next(s);
	for (int i = 0; i < n; i++)
	{
		cout << next[i] << " ";
	}
	cout << endl;
	delete[] next;
}
void print_nextval(string& s)
{
	int n = s.length();
	int* nextval = get_nextval(s);
	for (int i = 0; i < n; i++)
	{
		cout << nextval[i] << " ";
	}
	cout << endl;
	delete[] nextval;
}

