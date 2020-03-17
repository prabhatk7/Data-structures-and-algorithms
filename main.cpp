#include<iostream>
#include<algorithm>
using namespace std;

void wap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}
int main()
 {
	int a[]={1,3};
	wap(&a[0],&a[1]);
	cout<<a[0]<<a[1];
	return 0;
}
