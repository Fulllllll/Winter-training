/* ���������������г��ֵĴ���
����
����һ������Ϊ n �ķǽ��������һ���Ǹ������� k ��Ҫ��ͳ�� k �������г��ֵĴ���

���ݷ�Χ��0 \le n \le 1000 , 0 \le k \le 1000��n��1000,0��k��100��������ÿ��Ԫ�ص�ֵ���� 0 \le val \le 1000��val��100
Ҫ�󣺿ռ临�Ӷ� O(1)O(1)��ʱ�临�Ӷ� O(logn)O(logn)
ʾ��1
���룺
[1,2,3,3,3,3,4,5],3
����
����ֵ��
4
����
ʾ��2
���룺
[1,3,4,5],6
����
����ֵ��
0*/ 
int Bsearch(int* data,int r, double k)
{
    int l = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (data[mid] > k) r = mid - 1;
        else if (data[mid] < k) l = mid + 1;
    }
    return l;
}

int GetNumberOfK(int* data, int dataLen, int k) {
    return Bsearch(data, dataLen - 1, k + 0.5) - Bsearch(data,dataLen - 1, k - 0.5);
}

int main()
{
    int a[] = { 1,2,3,3,3,3,3,4,5 };
    printf("%d", GetNumberOfK(a, sizeof(a)/sizeof(a[0]), 3));
    return 0;
}
