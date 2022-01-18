/*旋转数组的最小数字
描述
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。

数据范围：1 \le n \le 100001≤n≤10000，数组中任意元素的值: 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
示例1
输入：
[3,4,5,1,2]
返回值：
1
示例2
输入：
[3,100,200,3]
返回值：
3
*/

//二分的变形 

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

