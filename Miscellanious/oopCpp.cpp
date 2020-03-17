#include <iostream>

using namespace std;

class student
{
    private:
    int roll;
    string name;
    int science;
    int maths;
    int english;
    public:
        student (int roll, string n, int science, int maths, int english)
        {
            this->roll=roll;
            this->name=n;
            this->science=science;
            this->maths=maths;
            this->english=english;
        }
        int total ();
        float grade ();

};
int student::total ()
{
    return maths+science+english;
}
float student::grade()
{

    return float(maths+science+english)/30;
}
int main()
{
    int roll, maths,science,english;
    string n;

    cout<<"enter your name"<<endl;
    cin>>n;
    cout<<"enter your roll no"<<endl;
    cin>>roll;
    cout << "enter marks in maths,science and english" << endl;
    cin>>maths>>science>>english;
    student s1(roll,n,science,maths,english);
    cout<<"Total marks="<<s1.total()<<endl;
    cout<<"Grade"<<s1.grade()<<endl;
    return 0;
}
