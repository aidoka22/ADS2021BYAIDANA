#include <cstdio>

#include <cstring>

#include <stack>

using namespace std;

char str[100];
int n;
int q[100];
int s=0,h; // stack is in [0, h)
// 1 2 2 2 3, h = 5
void push(int x) {
	q[h] = x; // q[h++] = x;
	h++;
}

void pop() {
	
	s++;
}
int size(){
    return h-s;
}
int front() {
	return q[s];
}

bool empty() {
	return h-s == 0;
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
      printf("%d\n",front());
      pop();}
      else{
      puts("error");
      }

    } else

    if (strcmp(str,"front") == 0)

    {
      if(!empty()){
      printf("%d\n",front());}
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