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
    int getDecimalValue(ListNode* head) {
        int num=0;
        int count=0;
        ListNode *temp= head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp=head;
        count=count-1;
        while(temp!=NULL){
            num=num+(pow(2,count)*temp->val);
            temp= temp->next;
            count--;
        }
        return num;
    }
};