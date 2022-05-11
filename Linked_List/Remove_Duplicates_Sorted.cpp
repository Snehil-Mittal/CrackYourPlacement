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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* rindex=head;
        ListNode* temp=head->next;
        int prev=head->val;
        while(temp!=NULL){
            if(temp->val!=prev){
                rindex->next=temp;
                rindex=temp;
                prev=rindex->val;
            }
            temp= temp->next;
        }
        rindex->next=NULL;
        return head;
    }
};