//detect and remove loop in a linked lists
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* ptr1, ptr2;
void detectLoop();
void removeLoop(struct node* ptr2);

void printList();
struct node* newNode(int val);

void printList()
{
    ptr1=head;
    cout<<"List: ";
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<" ";
        ptr1=ptr1->next;
    }
    cout<<"\n";
}

struct node* newNode(int val)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    return n;
};

void detectLoop()
{
    struct node* ptr1=head;
    struct node* ptr2=head;

        while(ptr1!=NULL&&ptr2!=NULL&&ptr2->next!=NULL)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
            if(ptr2==ptr1)
                {
                    cout<<"Loop Detected\n";
                    removeLoop(ptr1);
                    return ;
                }
        }

        cout<<"No loop detected, returning\n";

}

void removeLoop(struct node* ptr)
{
    ptr1=head;
    struct node* ptr2=ptr;
    while(1)
    {
        while(ptr2->next!=ptr2&&ptr2->next!=ptr1)
        {
            ptr2=ptr2->next;
        }
        if(ptr2->next==ptr1)
        {
            ptr2->next=NULL;
            cout<<"Loop removed\n";
            return ;
        }
        ptr1=ptr1->next;
    }
    printList();
}

int main()
{

    head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(5);
    head->next->next->next->next->next=newNode(6);
    head->next->next->next->next->next->next=newNode(7);
    head->next->next->next->next->next->next->next=newNode(8);
    head->next->next->next->next->next->next->next->next=head;

    //printList();

    detectLoop();
    printList();

    return 0;
}
