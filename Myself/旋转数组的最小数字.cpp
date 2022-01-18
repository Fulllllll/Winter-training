/*��ת�������С����
����
��һ������Ϊ n �ķǽ������飬����[1,2,3,4,5]������������ת������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����һ����ת���飬��������[3,4,5,1,2]������[4,5,1,2,3]�����ġ����ʣ���������һ����ת���飬�������е���Сֵ��

���ݷ�Χ��1 \le n \le 100001��n��10000������������Ԫ�ص�ֵ: 0 \le val \le 100000��val��10000
Ҫ�󣺿ռ临�Ӷȣ�O(1)O(1) ��ʱ�临�Ӷȣ�O(logn)O(logn)
ʾ��1
���룺
[3,4,5,1,2]
����ֵ��
1
ʾ��2
���룺
[3,100,200,3]
����ֵ��
3
*/

//���ֵı��� 

//C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 1) return -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else if (nums[mid] == nums[r]) r -= 1;
        }
        return nums[l];
    }

};

//C
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen)
{
    int l = 0;
    int r = rotateArrayLen - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (rotateArray[mid] > rotateArray[r]) l = mid + 1;
        else if (rotateArray[mid] < rotateArray[r]) r = mid;
        else if (rotateArray[mid] == rotateArray[r]) r -= 1;
    }
    return rotateArray[l];
}

