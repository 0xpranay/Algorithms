#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
    }
    Node(int val, Node* next)
    {
        this->val = val;
        this->next = next;
    }
    Node()
    {
        this->next = NULL;
    }
};
int main(void)
{
    Node  *n1, *n2, *n3, *n4, *n5;
    n1 = new Node(1);
    n2 = new Node(2);
    n3 = new Node(3);
    n4 = new Node(4);
    n5 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    Node* temp = n1;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    Node* dummy;
    dummy = n1;
    cout<<"Value in dummy is "<<dummy->val<<"\n";
    cout<<"Changing value in dummy to 99\n";
    dummy->val = 99;
    cout<<"Value in dummy is "<<dummy->val<<" value in n1 is "<<n1->val<<endl;
    Node* empty = new Node();
    cout<<"Next value of empty is "<<empty->next<<endl;
    Node* empty_next = empty->next;
    cout<<"empty_next value is "<<empty_next<<endl;
    empty_next = new Node(23423);
    cout<<"Value in next of empty and empty_next is "<<empty->val<<" "<<empty->next<<endl;
    return 0;
}