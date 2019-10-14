#include "iheaders.h"
int main(){
    //int a[] = {6,2,5,4,5,1,6};
    //int a[] = {6,4,2,6};
    int a[] = {1};
    int n = sizeof(a)/sizeof(a[0]);
    stack<int> stk;
    int l[n],r[n]; l[0] = -1, r[n-1]= n;
    stk.push(0);
    for (size_t i = 1; i < n; i++)
    {
        while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if(stk.empty()) l[i] = -1;
        else l[i] = stk.top();
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    stk.push(n-1);
    for(int i = n-2; i >= 0; --i){
        while(!stk.empty() && a[i] <= a[stk.top()]) stk.pop();
        if(stk.empty()) r[i] = n;
        else r[i] = stk.top();
        stk.push(i);
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << l[i] << "  ";
    }
    
    return 0;
}
