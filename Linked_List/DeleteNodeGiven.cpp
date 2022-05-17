#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};
class Solution{
    public: 
    void DeleteNode(Node* node){
        if(node==NULL)
            return;
        if(node->next==NULL){
            free(node);
        }
        else{
            while(node->next!=NULL){
                node->val=node->next->val;
                node=node->next;
            }
            free(node);
        }
        
    }
};

