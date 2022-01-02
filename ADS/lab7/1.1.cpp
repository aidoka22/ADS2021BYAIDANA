#include <iostream>
#include <cmath>
using namespace std;
 
const int N = 10;

class Node {
    public:
    char value;
    Node *ch[N];
    int cnt;
    bool withLeaf=false;
    string city="";
    Node(char value){
        this->value=value;
        this->cnt=1;
        for (int i=0; i<N; i++)
            ch[i]=NULL;
    }
};

class Trie{
    public:
    Node *root;
    Trie(){
        root=new Node(' ');
    }
    
    void insert(string ss,string city){
        Node *cur = root;
        for (int i=0; i<(int)ss.size(); i++){
            if (cur->ch[ss[i]-'0']!=NULL){
                cur->withLeaf=false;
                cur = cur-> ch[ss[i]-'0'];
                cur->cnt++;
            }
            else{
                Node *node = new Node(ss[i]);
                cur->withLeaf=false;
                cur->ch[ss[i]-'0'] = node;
                cur=node;
            }
        }
        cur->withLeaf=true;
        cur->city=city;
    }
    long long calculate( Node *node,int m){
        long long number=0;
        for (int i=0; i<10; i++){
            if (node->ch[i]!=NULL ){
                number += calculate(node->ch[i],m-1);
            }
        }
        if (node->city!=""){
            number = floor(pow(10, m)) - number;
            cout << node->city << " " << number << endl;
            return floor(pow(10, m));
        }
 
        return number;
    }
    
};

int main (){
    Trie *trie = new Trie();
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        string tt,city;
        cin >> tt >> city;
        if (tt.size()>m)
            cout << city << " 0" <<  endl;
        else
            trie->insert(tt,city);
    }
    trie->calculate(trie->root, m);
}
