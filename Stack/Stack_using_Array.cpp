#include<iostream>
using namespace std;

#define n 10

class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    } 
    void push(int x);
    void pop();
    int Top();
    bool isEmpty();
};

void stack::push(int x){
    if(top==n-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }

    top++;
    arr[top] = x;
    cout<<arr[top]<<" pushed into stack\n";
}

void stack::pop(){
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<arr[top]<<" popped from stack\n";
    top--;
}

int stack::Top(){
    if(top == -1){
        cout<<"No element in stack"<<endl;
        return 0;
    }
    cout<<"Top element of stack is: ";
    return arr[top];
}

bool stack::isEmpty(){
    return top==-1;
}

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    st.pop();
    cout<<st.isEmpty();
}