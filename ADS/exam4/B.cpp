#include <iostream>

using namespace std;
int a[1000][1000];

int main() {
    int n, q;
    cin >> n >> q;
     for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < q; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(a[x-1][y-1] == 1 && a[x-1][z-1] == 1 
        && a[y-1][x-1] == 1 && a[y-1][z-1] == 1 
        &&a[z-1][x-1] == 1 && a[z-1][y-1] == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}