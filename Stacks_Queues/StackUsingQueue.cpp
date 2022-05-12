#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    void print(queue<int> &q){
        queue<int> q1;
        while(!q.empty()){
            cout<<q.front()<<" ";
            q1.push(q.front());
            q.pop();
        } 
       while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        cout<<endl;
    }
    
    void push(int x) {
        q.push(x);
        //print(q);
    }
    
    int pop() {
        queue<int> q1;
        //print(q);
        while(q.size()!=1){
            q1.push(q.front());
            q.pop();
        }
        int a=q.front();
        q.pop();
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        return a;
    }
    
    int top() {
        queue<int> q1;
        while(q.size()!=1){
            q1.push(q.front());
            q.pop();
        }
        int a=q.front();
        q1.push(q.front());
        q.pop();
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        return a;
    }
    
    bool empty() {
        if(q.empty())
            return true;
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */