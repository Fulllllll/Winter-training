/* 数字在升序数组中出现的次数
描述
给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数

数据范围：0 \le n \le 1000 , 0 \le k \le 1000≤n≤1000,0≤k≤100，数组中每个元素的值满足 0 \le val \le 1000≤val≤100
要求：空间复杂度 O(1)O(1)，时间复杂度 O(logn)O(logn)
示例1
输入：
[1,2,3,3,3,3,4,5],3
复制
返回值：
4
复制
示例2
输入：
[1,3,4,5],6
复制
返回值：
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
