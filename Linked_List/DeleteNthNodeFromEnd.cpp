#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        
        int d=count-n-1;
        if(d<0)
            head=head->next;
        else{
        temp=head;
        while(d>0){
            temp=temp->next;
            d--;
        }
        temp->next=temp->next->next;
        }
        
        return head;
    }
};