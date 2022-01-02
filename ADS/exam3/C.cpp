#include<iostream>
#include<string>
#include<algorithm>

#define MAX 1000000

using namespace std;

int  *m=new int [MAX];

string longest_common_substring(string s,string t)
{
    for(int i=0;i<MAX;i++)
        m[i]=0;

    int d;
    int longest=0;

    for(int i=0;i<t.size();i++)
    {
        for(int j=s.size()-1;j>=0;j--)
        {
            if(s[j]==t[i])
            {

                 m[j+1]=m[j]+1;
            }
            else m[j+1]=0;
            if(m[j+1]>longest)
            {
                longest=m[j+1];
                d=j-longest+1;
            }
        }
    }
    if(longest==0)return "";
    return s.substr(d,longest);
}


int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        string t;
        cin>>t;
        s=longest_common_substring(s,t);
    }
    cout<<s<<endl;
    return 0;


}