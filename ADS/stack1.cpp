#include <cstdio>

#include <cstring>

#include <stack>

using namespace std;

 

stack<int> s;

char str[100];

int n;

int main(void)

{

  while(scanf("%s",&str))

  {

    if (strcmp(str,"push") == 0)

    {

      scanf("%d",&n);

      s.push(n);

      puts("ok");

    } else 

    if (strcmp(str,"pop") == 0)

    {
      if(!s.empty()){
      printf("%d\n",s.top());
      s.pop();}
      else{
      puts("error");
      }

    } else

    if (strcmp(str,"back") == 0)

    {
      if(!s.empty()){
      printf("%d\n",s.top());}
      else{
      puts("error");
      }

    } else

    if (strcmp(str,"size") == 0)

    {

      printf("%d\n",s.size());

    } else

    if (strcmp(str,"clear") == 0)

    {

      while(!s.empty()) s.pop();

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