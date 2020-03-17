#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

class ProblemSolution{
    public:
       string solution(int N, int A[], int X);

};

int fun1(string A,string B){
string AB=A.append(B);
    string BA=B.append(A);
    return AB.compare(BA) > 0? 1 :0;
}
string ProblemSolution :: solution(int N, int A[], int X)
{

    //write your code here
   map<int,int> m;
    vector<int> v;
    for(int i=0;i<N;i++){
    m[A[i]]++;
    }
    for(int i=0;i<N;i++){
    if(m[A[i]]==1)
       v.push_back(A[i]);
    }
    int l=v.size();
    if(l==0)
        return "-1";

    vector<int> v1;
    for(int i=0;i<=l-X;i++){
    if(v[i]>v[i+X-1]){
     for(int j=i;j<i+X;j++)
         v1.push_back(abs(v[j]));
    }
    }
   int l1=v1.size();
    if(l1==0)
        return "-2";

   //Converting int to string

    string s;
    vector<string> v2;
    for(int i=0;i<l1;i++){
        stringstream ss;
        ss<<v1[i];
        ss>>s;
        v2.push_back(s);
    }


    vector<string> v3;
    //making largest no with combination of X individual no
    vector<string>::iterator it1,it2;
    for(int i=0;i<l1;i+=X){
      it1=v2.begin()+i;
        it2=it1+X;

     sort(it1,it2,fun1);
        string s1=v2[i];
     for(int j=i+1;j<i+X;j++){
     s1=s1.append(v2[j]);

     }
        v3.push_back(s1);
    }
    int l3=v3.size();
    long int maxi=0,temp;
    for(int i=0;i<l3;i++){
    stringstream ss1;
        ss1<<v3[i];
        ss1>>temp;
        if(temp>maxi)
        maxi=temp;
    }
    string sr;
    stringstream ss2;
    ss2<<maxi;
    ss2>>sr;

    return sr;

}
//Your program will be evaluated by this main method and several test cases.

int main()
{
    int N, X;
    cin >> N;
    int A[N];
    for(int i=0; i<N ; i++)
    {
	    cin >> A[i];
    }
    cin >> X;
    ProblemSolution problemSolution;
    cout << problemSolution.solution(N,A,X);
}
