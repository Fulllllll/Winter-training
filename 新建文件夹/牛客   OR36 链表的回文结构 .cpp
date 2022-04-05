//  ţ��   OR36 ����Ļ��Ľṹ 

#include<assert.h>
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        assert(A);
        //����ָ��Ѱ���м��� 
        ListNode *p1 = A, *p2 = A;
        while(1)
        {
            p2 = p2->next;
            if(p2->next == NULL) break;
            p1 = p1->next;
            p2 = p2->next;
            if(p2->next == NULL) break;
        }
       	//�����м��� ���Ա����������� 
        ListNode *t = NULL;
        t = p1->next;
        p1->next = NULL;
        p1 = t;
        
        //�����벿�ֵ����� 
        ListNode *p3 = p1, *p4 = p2;
        while(p3 != p2)
        {
            t = p3;
            p3 = p3->next;
            t->next = p4->next;
            p4->next = t;
        }
        
        //������������ �жϻ��� 
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

