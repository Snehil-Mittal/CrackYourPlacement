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
    ListNode *reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void print(ListNode *l1){
        while(l1!=NULL)
        {
            cout<<l1->val<<" ";
            l1=l1->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse Linked List
        ListNode* nl1=reverse(l1);
        ListNode* nl2=reverse(l2);
        print(nl1);
        cout<<endl;
        print(nl2);
        cout<<endl;
        // Seeing which list is bigger;
        int count1=0; int count2=0;
        ListNode* temp=nl1;
        while(temp!=NULL){
            count1++;
            temp=temp->next;
        }
        temp=nl2;
        while(temp!=NULL){
            count2++;
            temp=temp->next;
        }

        ListNode* result;
        if(count2>count1){
            result=nl2;
        }
        else
        {
            result=nl1;
        }
        
        temp = result;
        //Calculating Sum
        int carry=0;
        ListNode * prev;
        while(nl1!=NULL && nl2!=NULL){
            int sum=(nl1->val+nl2->val+carry)%10;
            carry=(nl1->val+nl2->val+carry)/10;
            temp->val=sum;
            nl1=nl1->next;
            nl2=nl2->next;
            prev=temp;
            temp=temp->next;
        }
        print(result);
        cout<<endl;
        if(count1>count2){
            while(nl1!=NULL){
                int sum=(nl1->val+carry)%10;
                carry=(nl1->val+carry)/10;
                nl1->val=sum;
                prev=nl1;
                nl1=nl1->next;
            }
            if(carry==1){
                prev->next= new ListNode(carry);
            }
        }
        else if(count2>count1){
            ListNode * prev;
            while(nl2!=NULL){
                int sum=(nl2->val+carry)%10;
                carry=(nl2->val+carry)/10;
                nl2->val=sum;
                prev=nl2;
                nl2=nl2->next;
            }
            if(carry==1){
                prev->next= new ListNode(carry);
            }
        }
        else{
            if(carry==1){
                prev->next = new ListNode(carry);
            }
        }
        print(result);
        return reverse(result);
    }
};