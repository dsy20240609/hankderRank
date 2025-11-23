int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int> res;
    for(int i=0;i < n;++i) {
        int temp;
        cin>>temp;
        res.push_back(temp);
    }
    std::sort(res.begin(),res.end());
    for(size_t i=0;i < res.size();++i) {
        cout<<res[i] << " ";
    }
    cout<<endl;
    return 0;
}
