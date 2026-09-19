
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==nullptr && l2==nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int a=0;
        ListNode* temp1= l1;
        ListNode* temp2 = l2;
        while(temp1!=nullptr||temp2!= nullptr||a!= 0){
            int sum=a;
            if(temp1 !=nullptr){
                sum+= temp1->val;
                temp1 = temp1->next;
            }
            if ( temp2 != nullptr ){
                sum+= temp2->val;
                temp2= temp2->next;
            }
            int b = sum%10;
            a = sum / 10;
            ListNode* dummy1 = new ListNode(b);
            tail->next = dummy1;
            tail = tail->next;
        }
        return dummy->next;
    }
};