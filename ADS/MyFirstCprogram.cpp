#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

char st[100];
int h; // stack is in [0, h)
// 1 2 2 2 3, h = 5
void push(char x) {
	st[h] = x; // st[h++] = x;
	h++;
}

char pop() {
    if (h == 0) {
		cerr << "Stack error\n";
		exit(0);
	}
	return st[h-1];
	h--;
}

char back() {
	if (h == 0) {
		cerr << "Stack error\n";
		exit(0);
	}
	return st[h-1];
}

bool empty() {
	return h == 0;
}

void stack_example1() {
	string s;
    getline(cin, s);
	int n = s.length();
    int t;
	for (int i = 0; i < n; i++) {
		if (s=="push"){
			cin>>t;
			cout<<"ok";
			push(n);
		} else if (s=="back") { // s[i] is closing bracket
			back();}
		else if(s=="pop"){
			pop();
		}
        else if(s=="empty"){
            empty();
        }
	}
}


int main() {


	stack_example1();



	return 0;
}