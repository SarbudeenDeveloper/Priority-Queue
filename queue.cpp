#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(vector<int> &hT, int i) {
    int size = hT.size();
    int largest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;
    if(l < size && hT[l] > hT[i])
    {
        largest = l;
    }
    if(r < size && hT[r] > hT[i])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(&hT[largest], &hT[i]);
        heapify(hT, largest);
    }
}

void insertItem(vector<int> &hT, int newValue) {
    int size = hT.size();
    if(size == 0)
    {
        hT.push_back(newValue);
    } else {
        hT.push_back(newValue);
        for(int i=(size/2)-1; i>=0; i--)
          heapify(hT, i);
    }
}

void display(vector<int> &hT) {
    int size = hT.size();
    for(int i=0; i<size; i++)
     cout<<hT[i]<<" ";
}

void deleteNode(vector<int> &hT, int value) {
    int size = hT.size();
    int i;
    for(i=0; i<size; i++)
        if(hT[i] == value)
         break;
    swap(&hT[i], &hT[size-1]);
    hT.pop_back();
    for(int j = size / 2 - 1; j >= 0; j--)
      heapify(hT, j);
}

int main()
{
    vector<int> hT;
    insertItem(hT, 12);
    insertItem(hT, 54);
    insertItem(hT, 68);
    insertItem(hT, 73);
    insertItem(hT, 49);
    insertItem(hT, 102);
    deleteNode(hT, 54);
    display(hT);
    return 0;
}