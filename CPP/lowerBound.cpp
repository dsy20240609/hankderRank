int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector<int> res;
    for(int i = 0 ; i < n;++i) {
        int temp;
        cin>>temp;
        res.push_back(temp);
    } 
    int q;
    cin>>q;
    for(int i=0; i <q;++i) {
     int find;
     cin>>find;
     auto low=std::lower_bound (res.begin(), res.end(), find);
     if(low)   
    }
    return 0;
}
