#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int a=10;
    int *p, *q;
    p=&a;
    cout<<"p:"<<*p<<endl;
    q=p;
    cout<<"q:"<<*q<<endl;

    return 0;
}
