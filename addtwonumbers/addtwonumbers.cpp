#include <iostream>
#include <stdio.h>

using std::cout;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur1 = l1;
        ListNode h = ListNode();
        ListNode* cur = &h;
        int carry = 0;
        int sum = 0;

        while(l1 or l2){
            sum = 0;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum > 9 ? 1 : 0;
            sum %= 10;

            cur->next = new ListNode(sum);
            cur = cur->next;
        }

        if(carry){
            cur->next = new ListNode(1);
            cur = cur->next;
        }

        return h.next;
}

int main(){
    ListNode d1 = ListNode(8);
    ListNode d2 = ListNode(1, &d1);
    // ListNode d3 = ListNode(2, &d2);

    ListNode d4 = ListNode(0);
    // ListNode d5 = ListNode(6, &d4);
    // ListNode d6 = ListNode(5, &d5);

    ListNode* l = addTwoNumbers(&d2, &d4);
    
    ListNode* cur = l;
    while(cur != nullptr){
        cout << cur->val;
        cur = cur->next;
    }



    return 0;
}