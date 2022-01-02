#include <cstdio>
#include<iostream>
#include <cstring>

#include <deque>

using namespace std;

 

deque <int> s;

char str[100];

int n;

 

int main(void)

{

  while(scanf("%s",&str))

  {

    if (strcmp(str,"push_front") == 0)

    {
      s.push_front(n);

      puts("ok");

    } else if (strcmp(str,"push_back") == 0)

    {

      

      s.push_back(n);

      puts("ok");

    } 
    else 

    if (strcmp(str,"pop_front") == 0)

    {
      if(!s.empty()){
      
      printf("%d\n",s.front());
      s.pop_front();
      
      }
      else{
      puts("error");
      }

    } else 

    if (strcmp(str,"pop_back") == 0)

    {
      if(!s.empty()){
      
      printf("%d\n",s.back());
      s.pop_back();
      
      }
      else{
      puts("error");
      }

    }else 

    if (strcmp(str,"back") == 0)

    {
      if(!s.empty()){
      
      printf("%d\n",s.back());
      
      
      }
      else{
      puts("error");
      }

    }else

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

      while(!s.empty()) s.pop_front();

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