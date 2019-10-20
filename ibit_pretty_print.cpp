
// Q: https://www.interviewbit.com/problems/prettyprint/

void print(int n, vector<vector<int> >& arr){
    int t = n;
    n = 2*n-1;
    vector<int> tmp;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            tmp.push_back(0);
        }
        arr.push_back(tmp);
        tmp.clear();
    }
    int a = 0,b = n-1,c = n-1, d = 0;
    while(a<=b){
        for(int i = d; i <= b; ++i) {
            arr[a][i] = t;
        } a++;
        for(int i = a; i <= c; ++i) {
            arr[i][b] = t;
        } b--;
        for(int i = b; i >= d; --i) {
            arr[c][i] = t;
        } c--;
        for(int i = c; i >= a; --i) {
            arr[i][d] = t;
        } d++;
        t--;
    }
}
vector<vector<int> > Solution::prettyPrint(int n) {
    vector<vector<int> > arrr;
    print(n,arrr);
    return arrr;
}
