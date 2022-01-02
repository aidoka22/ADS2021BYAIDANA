#include <bits/stdc++.h>
using namespace std;
string currentArray[51];
void Sort1(vector<string> s, int n) 
{ 
	for (int i=1 ;i<n; i++) 
	{ 
		string temp = s[i]; 

		// Insert s[j] at its correct position 
		int j = i - 1; 
		while (j >= 0 && temp.length() < s[j].length()) 
		{ 
			s[j+1] = s[j]; 
			j--; 
		} 
		s[j+1] = temp; 
	} 
} 

int main()
{
	int n;
	cin>>n;
		for(int i=0;i<=n;i++){
			string s;
			getline(cin,s);
            vector<string> v;
			istringstream iss(s);
			do
			{
				string subs;
				iss >> subs;
		        v.push_back(subs);
			} while (iss);
            Sort1(v,v.size());
			for(int i = 0; i < v.size(); i++)
				cout << v[i] <<" ";
		}
		return 0;
}