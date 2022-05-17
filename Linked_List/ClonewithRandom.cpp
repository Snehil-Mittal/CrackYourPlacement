#include <iostream>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            Node *p= new Node(temp->val);
            Node* t=temp->next;
            temp->next=p;
            p->next=t;
            temp=temp->next->next;
        }
        
        // temp=head;
        // while(temp!=NULL){
        //     cout<<temp->random<<" ";
        //     temp=temp->next;
        // }
        //cout<<endl;
        
        temp=head;
        while(temp->next->next!=NULL){
           if(temp->random==NULL){
               temp->next->random=NULL;
           }
           else{
               temp->next->random=temp->random->next; 
           }
           temp=temp->next->next;
        }
        if(temp->random==NULL){
               temp->next->random=NULL;
           }
        else{
               temp->next->random=temp->random->next; 
        }
        
        // temp=head;
        // while(temp!=NULL){
        //     cout<<temp->random<<" ";
        //     temp=temp->next;
        // }
        Node* newhead = head->next;
        Node* newtemp=newhead;;
        temp=head;
        while(temp!=NULL){
            temp->next=temp->next->next;
            if(newtemp->next)
            {
                newtemp->next=newtemp->next->next;
            }
            else{
                newtemp->next=NULL;
            }
            temp=temp->next;
            newtemp=newtemp->next;
        }
        return newhead;
    }
};