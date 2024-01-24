// 1.=================================Stack using 2 queue================================

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }

        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
    }
    
    int pop() {
       int ele=que2.front();
       que2.pop();
       return ele;
    }
    
    int top() {
       return que2.front();
    }
    
    bool empty() {
        return que2.empty();
    }
};



// 2.-------------------------------------Using Queue rotation-----------------------------------

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i< q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int poped = q.front();
        q.pop();
        return poped;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
