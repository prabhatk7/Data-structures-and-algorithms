#include <iostream>
#include <vector>
using namespace std;



void InsertHeap(vector<int> &a,int n){
int i=n,temp=a[n];
while(temp>a[i/2] && i>1){
    a[i]=a[i/2];
    i=i/2;
}
  a[i]=temp;
}

void CreateHeap(vector<int> &a,int n){
for(int i=2;i<=n;i++)
    InsertHeap(a,i);
}

void PopHeap(vector<int> &a,int n){
int x=a[1];
a[1]=a[n];
int i=1,j;
j=2*i;
while(j<n-1){
   if(a[j]<a[j+1])
        j++;
   if(a[j]>a[i]){
    swap(a[i],a[j]);
    i=j;
    j=2*i;
   }
   else{
    break;
   }
}
a[n]=x;
}

void DeleteHeap(vector<int> &a,int n){
    for(int i=n;i>1;i--){
        PopHeap(a,i);
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    }
}

int main()
{
    vector<int> a={0,3,4,9,5,7,14,412,36,95,745,10};
    CreateHeap(a,11);
    for(int i=1;i<=11;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    DeleteHeap(a,11);

    return 0;
}
