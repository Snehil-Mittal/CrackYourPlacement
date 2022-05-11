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
   
    ListNode* insertBegin(ListNode* l1,int val){
        ListNode* temp=new ListNode(val);
        temp->next=l1;
        l1=temp;
        return l1;
    }
    void print(ListNode *l1){
        while(l1!=NULL)
        {
            cout<<l1->val<<" ";
            l1=l1->next;
        }
    }
    void addTwoNumbersHelp(ListNode *l1 , ListNode* l2,int &carry){
        if(l1->next==NULL){
            int sum=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            l1->val=sum;
            return;
        }
        else {
            addTwoNumbersHelp(l1->next,l2->next,carry);
            int sum=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            l1->val=sum;
            return;
        }
    }
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

        if(count2>count1){
            for(int i=0;i<abs(count1-count2);i++){
                l1=insertBegin(l1,0);
            }
        }
        else
        {
            for(int i=0;i<abs(count1-count2);i++){
                l2=insertBegin(l2,0);
            }
        }
        // print(l1);
        // cout<<endl;
        // print(l2);
        // cout<<endl;
        int carry=0;
        addTwoNumbersHelp(l1,l2,carry);
        if(carry==1){
                ListNode *temp = new ListNode(carry);
                temp->next=l1;
                l1=temp;
            }
        return l1;
    }
};