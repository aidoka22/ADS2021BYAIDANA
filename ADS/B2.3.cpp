#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
 
using namespace std;
 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color 0A");
    
    string s;
    getline(cin, s);
    auto flag = false;
    for (;;)
    {
        auto has_repeat = false;
        auto old_char = s[0u];
        for (size_t u = 1u; u < s.size(); ++u)
        {
            if (old_char == s[u])
            {
                s.erase(s.begin() + u - 1, s.begin() + u + 1);
                flag = !flag;
                has_repeat = true;
                break;
            }
            old_char = s[u];
        }
        if (s.empty() || !has_repeat)
        {
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
 
    system("pause");
    return 0;
}