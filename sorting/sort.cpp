#include <iostream>

using namespace std;



void BubbleSort(int a[],int n)
{
    if(n>1)
    {
        for(int i=0;i<n;i++)
        if(a[i]>a[i+1])
            swap(a[i],a[i+1]);
        BubbleSort(a,n-1);
    }
    return;
}

void InsertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int c=a[i],j=i-1;
        while(c<a[j] && j>=0)
        {
               a[j+1]=a[j];
               j--;
        }
        a[j+1]=c;
    }
    return;
}

void SelectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j=i,k=i;
        while(k<n)
        {
            if(a[k]<a[j])
                j=k;
            k++;
        }
        swap(a[i],a[j]);
    }
    return;
}

int Partition(int a[],int l,int h)
{
    int pivot=a[l],i=l+1,j=h;
    while(i<=j )
    {
        while(a[i]<pivot && i<h)
            {
                 i++;
            }

        while(a[j]>=pivot && j>l){
            j--;
        }

        if(i<j)
        swap(a[i],a[j]);
    }
     if(i>j)
     swap(a[l],a[j]);
    return j;
}

void QuickSort(int a[],int l,int h)
{
   int p;
   if(h>l)
   {
   p=Partition(a,l,h);
   QuickSort(a,l,p);
   QuickSort(a,p+1,h);
   }
   return;
}

void Merge(int a[],int l,int h){
int ni=((h+l)/2)+1, nj=h+1;
int i=l,j=ni,k=0;
int *b=new int [h-l+1];
while(i<ni && j<nj){
    if(a[i]>a[j])
        b[k++]=a[j++];
    else
        b[k++]=a[i++];
}
for(;i<ni;)
    b[k++]=a[i++];
for(;j<nj;)
    b[k++]=a[j++];
for(int x=l;x<=h;x++)
    a[x]=b[x-l];
delete []b;
}

void MergeSort(int a[],int l,int h){
    if(h>l){
MergeSort(a,l,(h+l)/2);
MergeSort(a,((h+l)/2)+1,h);
Merge(a,l,h);
    }
}

int main()
{
    int a[]={4,3,2,1,55,1000,100};
    int n=6;
    MergeSort(a,0,n);
    for(int i=0;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
