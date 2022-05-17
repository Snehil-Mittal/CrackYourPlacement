#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int count1=0;
        int count2=0;
        // These counts basically how many times reached NULL
        while(count1!=2 && count2!=2){
            if(tempA==NULL){
                tempA=headB;
                count1++;
            }
            if(tempB==NULL){
                tempB=headA;
                count2++;
            }
            if(tempA==tempB){
                return tempA;
            }
            else{
                tempA=tempA->next;
                tempB=tempB->next;
            }
        }
        return NULL;
    }
};