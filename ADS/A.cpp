#include <cstdio>

#include <cstring>

#include <stack>

using namespace std;

char str[100];
int n;
int s[100];
int h; 
void push(int x) {
	s[h] = x; // s[h++] = x;
	h++;
}

void pop() {
	
	h--;
}
int size(){
    return h;
}
int back() {
	return s[h-1];
}

bool empty() {
	return h == 0;
}
int main(void)

{

  while(scanf("%s",&str))

  {

    if (strcmp(str,"push") == 0)

    {

      scanf("%d",&n);

      push(n);

      puts("ok");

    } else 

    if (strcmp(str,"pop") == 0)

    {
      if(!empty()){
      printf("%d\n",back());
      pop();}
      else{
      puts("error");
      }

    } else

    if (strcmp(str,"back") == 0)

    {
      if(!empty()){
      printf("%d\n",back());}
      else{
      puts("error");
      }

    } else

    if (strcmp(str,"size") == 0)

    {

      printf("%d\n",size());

    } else

    if (strcmp(str,"clear") == 0)

    {

      while(!empty()) pop();

      puts("ok");

    } else

    if (strcmp(str,"exit") == 0)
{

      puts("bye");

      break;

    }
    

  }

  return 0;

}