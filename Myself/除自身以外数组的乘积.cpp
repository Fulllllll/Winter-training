/*
  ����  238. ��������������ĳ˻�
  ����һ����������?nums������ ����?answer?������?answer[i]?����?nums?�г�?nums[i]?֮�������Ԫ�صĳ˻�?��

��Ŀ���� ��֤ ����?nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����? 32 λ ������Χ�ڡ�

�벻Ҫʹ�ó���������?O(n) ʱ�临�Ӷ�����ɴ��⡣

?

ʾ�� 1:

����: nums = [1,2,3,4]
���: [24,12,8,6]
ʾ�� 2:

����: nums = [-1,1,0,-3,3]
���: [0,0,9,0,0]
?

��ʾ��

2 <= nums.length <= 105
-30 <= nums[i] <= 30
��֤ ����?nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����? 32 λ ������Χ��
?

���ף�������� O(1)?�Ķ���ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/product-of-array-except-self
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 

//	ǰ׺�˻����׺�˻� 

 
// C
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int* p = (int*)malloc(numsSize * 4);
	*returnSize = numsSize;
	p[0] = 1;
	for (int i = 1; i < numsSize; i++)
	{
		p[i] = p[i - 1] * nums[i - 1];
	}
	int r = 1;
	for (int i = numsSize - 1; i >= 0; i--)
	{
		p[i] = p[i] * r;
		r = r * nums[i];
	}
	return p;
}
// C++ 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] ��ʾ���� i �������Ԫ�صĳ˻�
        // ��Ϊ����Ϊ '0' ��Ԫ�����û��Ԫ�أ� ���� answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R Ϊ�Ҳ�����Ԫ�صĳ˻�
        // �տ�ʼ�ұ�û��Ԫ�أ����� R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // �������� i����ߵĳ˻�Ϊ answer[i]���ұߵĳ˻�Ϊ R
            answer[i] = answer[i] * R;
            // R ��Ҫ�����ұ����еĳ˻������Լ�����һ�����ʱ��Ҫ����ǰֵ�˵� R ��
            R *= nums[i];
        }
        return answer;
    }
};
