#include<bits/stdc++.h>
using namespace std;
/*
for idx p:
    parent is floor(p - 1 / 2)
    left child is 2 * p + 1
    right child is 2 * p + 2
*/
class Heap
{
    public:
    vector<int> heap;
    int idx = 0;
    int heap_size = 0;
    Heap(int n)
    {
        heap = vector<int> (n, INT_MIN);
        heap_size = 0;
    }
    void heap_up(int i)
    {
        while(i != 0 && heap[(i - 1) / 2] > heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void heap_down()
    {
        int i = 0;
        while(i < idx)
        {
           int left = (2 * i) + 1;
           int right = (2 * i) + 2;
           if(right < idx && heap[right] < heap[left] && heap[right] < heap[i] && heap[right] != INT_MIN)
           {
               swap(heap[right], heap[i]);
               i = right;
           } 
           else if(left < idx && heap[left] < heap[right] && heap[left] < heap[i] && heap[left] != INT_MIN)
           {
               swap(heap[left], heap[i]);
               i = left;
           }
           else break;
        }
    }
    bool empty()
    {
        return heap[0] == INT_MIN ? true : false;
    }
    void insert(int k)
    {
        if(idx == heap.size())
        {
            cout<<"Heap is full "<<endl;
            return;
        }
        heap[idx] = k;
        heap_up(idx);
        idx++;
        heap_size++;
    }
    void pop()
    {
        if(heap[0] == INT_MIN)
        {
            cout<<"Heap is empty"<<endl;
            return;
        }
        heap[0] = heap[idx - 1];
        heap[idx - 1] = INT_MIN;
        heap_down();
        idx--;
        heap_size--;
    }
    void printheap()
    {
        for(int i = 0;i < heap.size(); i++)
        {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
    int peek()
    {
        return heap[0];
    }
    int size()
    {
        return heap_size;
    }
};
int main(void)
{
    int n, k, c;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    Heap h = Heap(n);
    while(1)
    {
        cout<<"Enter 1 for insert\n2 for pop\n3 to peek\n4 for size\n5 for empty\n0 to exit  ";
        cin>>c;
        switch (c)
        {
        case 1:
            cout<<"Enter element to insert"<<endl;
            cin>>k;
            h.insert(k);
            break;
        case 2:
            cout<<"Popping"<<endl;
            h.pop();
            break;
        case 3:
            cout<<"Minimum element is "<<" ";
            cout<<h.peek()<<"\n";
            break;
        case 4:
            cout<<"Size of heap is "<<h.size()<<endl;
            break;
        case 5:
            cout<<h.empty()<<endl;
            break;
        case 6:
            h.printheap();
            break;
        case 0:
            cout<<"Exiting.....\n";
            return 0;
        default:
            return 0;
        }
    }
}