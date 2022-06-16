#include <iostream>
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
    ListNode* reverseHelp(ListNode* temp, ListNode* rightend){
        ListNode* prev=NULL;
        ListNode* curr=temp;
        bool flag=true;
        while(curr!=rightend){
            ListNode* p=curr->next;
            if(flag)
            {
                curr->next=rightend;
                flag=false;
            }
            else{
                curr->next=prev;
            }
            prev=curr;
            curr=p;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        
        ListNode *temp=head; int count=1;
        while(count<left-1){
            count++;
            temp=temp->next;
        }
        ListNode* end=temp->next;
        count++;
        while(count<right){
            count++;
            end=end->next;
        }
        if(left==1)
        head=reverseHelp(temp, end->next);
        else
        temp->next=reverseHelp(temp->next, end->next);  
        
        return head;
    }
};