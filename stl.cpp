#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


void VectorDemo()
{
   vector<int> a={3,5,8,6,4,2};
    a.push_back(7);

   /* for(int x:a)
    cout<<x<<endl;
    */
    vector<int>::iterator it=a.begin();
    for(;it!=a.end();it++)
        cout<<*it;

    sort(a.begin(),a.end());
    cout<<endl;

    for(int x:a)
        cout<<x;

    bool present=binary_search(a.begin(),a.end(),5);
    cout<<endl<<present<<endl;

    vector<int>::iterator it1=lower_bound(a.begin(),a.end(),5);
    vector<int>::iterator it2=upper_bound(a.begin(),a.end(),5);
    cout<<*it1<<endl;
    cout<<it2-it1<<endl;

    return;
}

void SetDemo()
{
    set<int> s;
    s.insert(5);
    s.insert(9);
    s.insert(4);
    s.insert(7);

    for(int x:s)
        cout<<x;

   set<int>::iterator it1=s.find(5);
   if(it1!=s.end())
    cout<<endl<<"element found "<<*it1<<endl;
   else
    cout<<"element not found"<<endl;

   set<int>::iterator it2=s.lower_bound(6);
   if(it2==s.end())
    cout<<"could'nt find something like that"<<endl;
   else
    cout<<*it2<<endl;

    s.erase(5);
    for(int x:s)
        cout<<x;
    cout<<endl;

   return;
}


int main()
{
   SetDemo();


    return 0;
}
