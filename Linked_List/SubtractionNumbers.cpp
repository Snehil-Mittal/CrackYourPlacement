#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

//Reverse Linked List
Node* reverse(Node *temp){
    Node* prev = NULL;
    Node* cur=temp;
    while(cur!=NULL){
        Node* p=cur->next;
        cur->next=prev;
        prev=cur;
        cur=p;
    }
    return prev;
}

// Borrow Rule Update
void borrowCall(Node* &revtemp,int inc){
    revtemp->data=(revtemp->data)+inc;
    if(revtemp->next->data==0){
        borrowCall(revtemp->next,9);
    }
    else{
        revtemp->next->data=(revtemp->next->data)-1;
        return;
    }
}

//Print Linked List
void print(Node *rev){
    while(rev!=NULL){
        cout<<rev->data<<" ";
        rev=rev->next;
        
    }
    cout<<endl;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    // Count Number of Nodes
    int count1=0;
    int count2=0;
    Node* temp1=l1; Node* temp2=l2;
    while(temp1!=NULL){
        count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        count2++;
        temp2=temp2->next;
    }
    
    int diff=abs(count1-count2);
    int x=count1;
    int y=count2;
    
    // 1st check for bigger number after removing pre-added zeros on basis of count
    temp1=l1;
    temp2=l2;
    while((temp1->data) == 0 ){
            count1--;
            if(temp1->next==NULL)
                break;
            temp1=temp1->next;
    }
    while((temp2->data) == 0){
            count2--;
            if(temp2->next==NULL)
                break;
            temp2=temp2->next;
    }
    
    // Add 0s in the front to equalize count of digits for subtraction.
    if(x>=y){
        while(diff){
            Node* p=new Node(0);
            p->next=l2;
            l2=p;
            diff--;
        }
    }
    else{
        while(diff){
            Node* p=new Node(0);
            p->next=l1;
            l1=p;
            diff--;
        }
    }
    
    // 2nd check for finding the bigger number if equality is the case, by looking the digits value.
    temp1 = l1;
    temp2 = l2;
    while(temp1->data==temp2->data && temp1->next!=NULL && temp2->next!=NULL ){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    bool flag2=false;
    if((temp1->data)>(temp2->data)){
        flag2=true;
    }
    
    Node *templ2=l2;
    Node *templ1=l1;
    bool flag = count1==count2 && flag2;
   
    Node* revl1=reverse(l1);
    Node* revl2=reverse(l2);
    Node *reshead=NULL;
   
    if(count1>count2 || flag){
        while(revl1!=NULL){
            if(revl1->data >= revl2->data){
                Node *temp= new Node((revl1->data)-(revl2->data));
                temp->next=reshead;
                reshead=temp;
            }
            else{
                borrowCall(revl1,10);
                Node* temp= new Node((revl1->data)-(revl2->data));
                temp->next=reshead;
                reshead=temp;
            }
            revl1=revl1->next;
            revl2=revl2->next;
            
        }
    }
    else{
        while(revl2!=NULL){
            if(revl2->data >= revl1->data){
                Node *temp= new Node((revl2->data)-(revl1->data));
                temp->next=reshead;
                reshead=temp;
            }
            else{
                borrowCall(revl2,10);
                Node* temp= new Node((revl2->data)-(revl1->data));
                temp->next=reshead;
                reshead=temp;
            }
            revl1=revl1->next;
            revl2=revl2->next;
            
        }

    }
  while(reshead->data==0 && reshead->next!=NULL){
      reshead=reshead->next;
  }
  return reshead;
    
}