#include <iostream>
using namespace std;

#define SIZE 5

void push(int val);
void pop();
void printStack();

struct stack
{
    int a[SIZE];
    int top;
}st;

void push(int val)
{
    if(st.top>=SIZE-1)
    {
        cout<<"Stack overflow\n";
        return ;
    }

    st.top++;
    st.a[st.top]=val;
        cout<<"Pushed onto stack\n";

    printStack();
}

void pop()
{
    if(st.top==-1)
    {
        cout<<"stack underflow";
        return ;
    }

        cout<<"Element popped is :"<<st.a[st.top]<<endl;
        st.top--;
        printStack();
}

void printStack()
{
    if(st.top==-1)
    {
        cout<<"Stack empty\n";
        return ;
    }

        cout<<"Stack is:\n";
    for(int i=st.top; i>=0; i--)
    {
        cout<<st.a[i]<<" ";
    }
}

int main()
{
    st.top=-1;

    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    push(5);

    return 0;
}
