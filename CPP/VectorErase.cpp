#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;++i) {
        int temp;
        cin>>temp;
        res.push_back(temp);
    }
    int q1;
    cin>>q1;
    if(q1<= static_cast<int>(res.size())) {
        res.erase(res.begin()+q1-1);
    }
    int start;
    int end;
    cin>>start>>end;
    res.erase(res.begin()+start-1,res.begin()+end-1);
    cout<< res.size() << endl;
    for(size_t i = 0;i < res.size();++i) {
        cout<< res[i] << " ";
    }
    cout << endl;
    return 0;
}
