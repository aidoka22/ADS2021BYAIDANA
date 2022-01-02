#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    deque<int> dq1, dq2;
    while(n--){
        char c;
        cin >> c;
        if(c == '+'){
            int x;
            cin >> x;
            if(dq1.size() == dq2.size()){
                dq2.push_back(x);
                int k =dq2.front();
                dq2.pop_front();
               dq1.push_back(k);
            }
            else{
               dq2.push_back(x);
            }
        }
        else if(c == '-'){
            if(dq1.size() ==dq2.size()){
                int k =dq2.front();
               dq2.pop_front();
               dq1.push_back(k);
                cout <<dq1.front() << "\n";
               dq1.pop_front();

            }
            else{
                cout <<dq1.front() << "\n";
               dq1.pop_front();
            }
        }
        else{
            int x;
            cin >> x;
            if(dq1.size() ==dq2.size()){
               dq1.push_back(x);
            }
            else{
               dq2.push_front(x);
            }
        }
    }
}