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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int count1=0; int count2=0;
        ListNode* temp=l1;
        while(temp!=NULL){
            count1++;
            temp=temp->next;
        }
        temp=l2;
        while(temp!=NULL){
            count2++;
            temp=temp->next;
        }
        int carry=0;
        ListNode* result;
        ListNode* prev;
        if(count1>=count2){
            result=l1;
            while(l2!=NULL){
                int sum=(l1->val+l2->val+carry)%10;
                carry=(l1->val+l2->val+carry)/10;
                l1->val=sum;
                prev=l1;
                l1=l1->next;
                l2=l2->next;
            }
            if(l1!=NULL)
            {
                while(l1!=NULL){
                int sum=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                l1->val=sum;
                prev=l1;
                l1=l1->next;
                }
            }
            if(carry){
                temp= new ListNode(carry);
                prev->next=temp;
            }
        }
        else{
            result=l2;
            while(l1!=NULL){
                int sum=(l1->val+l2->val+carry)%10;
                carry=(l1->val+l2->val+carry)/10;
                l2->val=sum;
                prev=l2;
                l1=l1->next;
                l2=l2->next;
            }
             if(l2!=NULL)
             {
                while(l2!=NULL){
                int sum=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                l2->val=sum;
                prev=l2;
                l2=l2->next;
                }
             }
            if(carry){
                temp= new ListNode(carry);
                prev->next=temp;
            }
        }
        return result;
    }
};