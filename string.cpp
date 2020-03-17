#include <iostream>
#include <string.h>

using namespace std;

int wordcount (string p)
{
    int words=1;
    for (int i=1;p[i]!='\0';i++)
    {
        if (p[i]==' ' && p[i-1]!=' ' && p[i+1]!='\0')
            words++;
    }
    return words;
}

/*string revstring (string p)
{
    int l=p.length;

    char *b;
    b= new char [p.length];
    int j=0;
    for (j=0,l=l-1;l>=0;j++,l--)
        b[j]=p[k];
    return b;
}
*/

void BitDuplicate(string s)
{
    cout<<s<<endl;
    long int h=0, l;
    for (int i=0;s[i]!='\0';i++)
    {
        l=1;
       l=l<<(s[i]-97);
       if((h&l)>0)
        cout<< s[i] << " is duplicate"<<endl;
       else
        h=(h|l);
    }
}

void perm(string s,int k)
{
  static string result=s;
  //cout<<result;
  static int pos[4]={0};
  int i;

  for( i=0;s[i]!='\0' && s[k]!='\0';i++)
  {
      if(pos[i]==0)
      {
      pos[i]=1;
      result[k]=s[i];

      perm(s,k++);
      pos[i]=0;
      }
  }
  if(s[k]=='\0')
  cout<<result<<endl;

}

void Perm(char s[], int k)
{
    static int a[10]={0};
    static char res[10];
    static int t=0;
    int i;
    if (s[k]=='\0')
    {
        res[k]='\0';
        cout<<res<<endl;
        t++;
    }
    else
    {
        for (i=0;s[i]!='\0';i++)
        {
            if (a[i]=='\0')
            {
                res[k]=s[i];
                a[i]=1;
                Perm (s,k+1);
                a[i]=0;
            }
        }
    }
    cout<<"total= "<<t<<endl;
}

int main()
{
    char s[]="PQRSTU";

   //cout<<revstring(s);
   //BitDuplicate(s);
    Perm(s,0);
    return 0;
}
