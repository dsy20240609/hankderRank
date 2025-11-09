// not working version, recursion and backtrack but i don't know what is the correct format

void helper(int n, int left, int right, vector<char>& temp, vector<string>& res);
vector<string> generateAngleBracketSequences(int n) {
    vector<string> res;
    if(n ==0) {return res;}
    vector<char> temp;
    int left=0;
    int right=0;
    helper(n,left,right,temp,res);
    return res;
}
void helper(int n, int left, int right, vector<char>& temp, vector<string>& res) {
    if(temp.size() == 2*n) {
        res.push_back(string(temp.begin(),temp.end()));
        temp.clear();
        return;
    }
    if(left<n && right < n && left == right) {
        left++;
        temp.push_back('<');
        helper(n,left,right,temp,res);
    } else if ( left < n && right < n && left > right) {
        temp.push_back('<');
        left++;
        helper(n,left,right,temp,res);
        temp.pop_back();
        left--;
        temp.push_back('>');
        right++;
        helper(n,left,right,temp,res);
    } else if (left == n && right <n) {
        temp.push_back('>');
        right++;
        helper(n,left,right,temp,res);
    } else {
        return;
    }
}