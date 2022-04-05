//  牛客   OR36 链表的回文结构 

#include<assert.h>
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        assert(A);
        //快慢指针寻找中间结点 
        ListNode *p1 = A, *p2 = A;
        while(1)
        {
            p2 = p2->next;
            if(p2->next == NULL) break;
            p1 = p1->next;
            p2 = p2->next;
            if(p2->next == NULL) break;
        }
       	//调整中间结点 ，以便进行下面操作 
        ListNode *t = NULL;
        t = p1->next;
        p1->next = NULL;
        p1 = t;
        
        //逆序后半部分单链表 
        ListNode *p3 = p1, *p4 = p2;
        while(p3 != p2)
        {
            t = p3;
            p3 = p3->next;
            t->next = p4->next;
            p4->next = t;
        }
        
        //变量两个链表 判断回文 
        ListNode *pp1 = A, *pp2 = p2;
        while(pp1!=NULL && pp2!=NULL)
        {
            if(pp1->val != pp2->val)
                return 0;
            pp1 = pp1->next;
            pp2 = pp2->next;
        }
        return 1;
    }
};

