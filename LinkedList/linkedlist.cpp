#include <iostream>
#include <stdlib.h>

using namespace std;

struct node* head=NULL;

struct node{
    int data;
    struct node* next;
};

void insert_at_begin()
{
    int val;
    cout<<"Enter the value to be inserted at beginning"<<endl;
    cin>>val;

    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->next=head;
    head=n;
}

void insert_at_end()
{
    int val;
    cout<<"Enter the value to be inserted at end"<<endl;
    cin>>val;

    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;

    struct node *ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=n;

}

void insert_after_position()
{
    int val, position;
    cout<<"Enter the value to be inserted after position"<<endl;
    cin>>val;

    cout<<"Enter the position 'after' which it needs to be inserted"<<endl;
    cin>>position;

    struct node *p=head;

    int count=1;
    while(count<position)
    {
        p=p->next;
        count++;
    }

    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->next=p->next;
    p->next=n;

}

void print_list(struct node* p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}



int main()
{
    int option;
    while(true)
    {
        cout<<"\nChoose an option : "<<endl;
        cout<<"1. Insert at beginning "<<endl;
        cout<<"2. Insert at last "<<endl;
        cout<<"3. Insert after positon "<<endl;
        cout<<"4. Print List "<<endl;
        cout<<"10. Exit "<<endl;

        cin>>option;

        switch(option)
        {
        case 1:
            insert_at_begin();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_after_position();
            break;
        case 4:
            print_list(head);
            break;
        case 10:
            exit(0);
            break;
        default:
            cout<<"Please make a valid choice\n";
            break;
        }

    }

    print_list(head);

    return 0;
}
