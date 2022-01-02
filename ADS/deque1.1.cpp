#include <cstdio>

#include <cstring>

#include <stack>

using namespace std;

char str[1000000];
int n;
int dq[1000000];
int s=0,h; // stack is in [0, h)
// 1 2 2 2 3, h = 5
void push_front(int x) {
  s--;
	dq[s] = x; // dq[h++] = x;
}
void push_back(int x) {
	dq[h] = x; // dq[h++] = x;
	h++;
}

void pop_front() {	
	s++;
}
void pop_back() {
	
	h--;
}
int size(){
    return h-s;
}
int front() {
	return dq[s];
}
int back() {
	return dq[h-1];
}
bool empty() {
	return h-s == 0;
}
int main(void)

{

  while(scanf("%s",&str))

  {

    if (strcmp(str,"push_back") == 0)

    {

      scanf("%d",&n);

      push_back(n);

      puts("ok");

    }else if (strcmp(str,"push_front") == 0)

    {

      scanf("%d",&n);

      push_front(n);

      puts("ok");

    }  else 

    if (strcmp(str,"pop_front") == 0)

    {
      if(!empty()){
      printf("%d\n",front());
      pop_front();}
      else{
      puts("error");
      }

    }else  if (strcmp(str,"pop_back") == 0)

    {
      if(!empty()){
      printf("%d\n",back());
      pop_back();}
      else{
      puts("error");
      }

    }else

    if (strcmp(str,"back") == 0)

    {
      if(!empty()){
      printf("%d\n",back());}
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

    } 
    else

    if (strcmp(str,"size") == 0)

    {

      printf("%d\n",size());

    } else

    if (strcmp(str,"clear") == 0)

    {

      while(!empty()) pop_front();

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