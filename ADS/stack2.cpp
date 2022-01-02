#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
queue <int> s;
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
      
      printf("%d\n",s.front());
      s.pop();
      
      }
      else{
      puts("error");
      }

    } else

    if (strcmp(str,"front") == 0)

    {
      if(!s.empty()){
         
      printf("%d\n",s.front());}
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