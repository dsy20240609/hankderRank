// this solution simulate the dp progress, but one of the test case fail because of time out.
// maybe the vector operation is too time consuming.
// there are also test case that fail but i don't understand why it fails.

string countInstallationSequences(int n) {
    if(n == 0) {return to_string(1);}
    if(n == 1) {return to_string(1);}
    if(n ==2 ) {return to_string(2);}
    vector<vector<vector<int>>> temp;
    temp.push_back({{1}}); 
    temp.push_back({{1}});   
    temp.push_back({{1,1},{2}});
    for(int i = 3 ; i <=n;++i) {
        vector<vector<int>> pre1=temp[i-1];
        vector<vector<int>> pre2=temp[i-2];
        for(size_t j =0; j < pre1.size();++j) {
            pre1[j].push_back(1);
        }
        for(size_t k = 0; k< pre2.size();++k) {
            pre2[k].push_back(2);
        }
        vector<vector<int>>  v3= pre1; 
        v3.insert(v3.end(), pre2.begin(), pre2.end()); 
        temp.push_back(v3);
    }
    return to_string(temp[n].size());
}

// easy way to only get counts, but 9/15 test case pass
string countInstallationSequences(int n) {
    if(n==0 || n ==1) return to_string(1);
    vector<int> res(n+1,0);
    res[0]=1;
    res[1]=1;
    
    for(int i =2;i<=n;++i) {
        res[i]=res[i-1]+res[i-2];
    }
    return to_string(res[n]);
}

// use long long but, 10/15 test case passes, not sure about the reason
string countInstallationSequences(int n) {
    if(n==0 || n ==1) return to_string(1);
    vector<long long> res(n+1,0);
    res[0]=1;
    res[1]=1;
    
    for(int i =2;i<=n;++i) {
        res[i]=res[i-1]+res[i-2];
    }
    return to_string(res[n]);
}

// another space optimization solution
    if (n == 0 || n == 1) return "1";

    long long prev2 = 1; // dp[0]
    long long prev1 = 1; // dp[1]
    long long curr = 0;

    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return to_string(curr);

