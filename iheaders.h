#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include <initializer_list>
#include<unordered_set>
#include<unordered_map>
#include<typeinfo>
#define pii pair<int,int> 
#define sz(a) sizeof(a)/sizeof(a[0])
using namespace std;
void show(int x){
    int bit[32];
    for(int i = 0; i < 32; ++i) {bit[i] = (x&1); x>>=1;}
    for (size_t i = 0; i < 32; i++)
    {
        cout << bit[32-i] << "  ";
    }
}
