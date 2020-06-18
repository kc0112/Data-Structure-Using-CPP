#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>&hT)
{
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

void Swap(int *a,int *b)
{
   int temp= *b;
   *b=*a;
   *a=temp;
}

void heapify(vector<int> &hT,int i)
{
    int Size=hT.size();
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<Size&&hT[l]<hT[largest])
        largest=l;
    if(r<Size&&hT[r]<hT[largest])
        largest=r;

    if(largest!=i)
    {
        Swap(&hT[i],&hT[largest]);
        if(largest!=Size-1)
          heapify(hT,largest);            //checking subtree of largest
    }
}

void insertion(vector<int>&hT,int newnum)
{
    int Size=hT.size();
        hT.push_back(newnum);
      if(Size!=0)
      {
          for(int i{Size/2-1};i>=0;i--)
            {
                heapify(hT,i);    //checking from  leaf to top
            }
      }
}

void deleteNode(vector<int>&hT,int num)
{
    int Size=hT.size();
    int i;
    for(i=0;i<Size;i++)
        if(num==hT[i])
          break;

    Swap(&hT[i],&hT[Size-1]);

    hT.pop_back();
    for(i=Size/2-1;i>=0;i--)
        heapify(hT,i);
}

int main()
{
   vector<int>heapTree;
   insertion(heapTree,3);
   insertion(heapTree,4);
   insertion(heapTree,9);
   insertion(heapTree,5);
   insertion(heapTree,2);

    cout << "Min-Heap array : ";
    printArray(heapTree);

    deleteNode(heapTree,9);

    cout<<"After deleting element : ";
    printArray(heapTree);

}

