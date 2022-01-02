#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000;
map<string, bool> used;
map<char, int> nxt[MAX];
int whole[MAX], mx = 2, q;
void push(string x) {
	s[h] = x; // s[h++] = x;
	h++;
}

void pop(string x) {
	h--;
}
int count(){
    for (int i = 0; i < s.size(); i++) {
				x = nxt[x][s[i]];
				if (x == 0) {
					cout << 0 << "\n";
					goto here;
				}
			}
			cout << whole[x] << "\n";  
			here:;
}
string back() {
	return s[h-1];
}

bool empty() {
	return h == 0;
}
int main(void)

{

  while(scanf("%s",&str))

  {

    if (strcmp(str,"+") == 0)

    {

      scanf("%d",&n);

      push(n);

      puts("ok");

    } else 

    if (strcmp(str,"-") == 0)

    {
      scanf("%d",&n);
      if(!empty()){
      printf("%d\n",back());
      pop(n);}
      else{
      puts("error");
      }

    } else
    if (strcmp(str,"?") == 0)

    {


    } 
  }
  return 0;

}