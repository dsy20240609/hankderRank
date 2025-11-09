int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int size;
    int query;
    cin>>size>>query;
    vector<vector<int>> res;
    for(int i =0 ;i<size;++i) {
        int vLength;
        cin>>vLength;
        vector<int> temp;
        for(int j=0;j<vLength;++j) {
            int value;
            cin>>value;
            temp.push_back(value);
        }
        res.push_back(temp);
    }
    for(int k=0; k < query;++k) {
       int row;
       int column;
       cin>>row>>column;
       cout<<res[row][column]<<endl; 
    }
    return 0;
}