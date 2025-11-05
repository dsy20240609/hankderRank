vector<string> minTasksToCancelForNoConflict(string digits) {
    map<int,vector<cha>> telephoneMap= {
        {0,{'0'}},
        {1,{'1'}},
        {2,{'a','b','c'}},
        {3,{'d','e','f'}},
        {4,{'g','h','i'}},
        {5,{'j','k','l'}},
        {6,{'m','n'.'o'}},
        {7,{'p','q','r','s'}},
        {8,{'t','u'.'v'}},
        {9,{'w','x','y','z'}
    };
    vector<string> res;
    int level=0;
    string value ="";
    backtrack(telephoneMap,res,digits,level,value);
    return res;
}

void backtrack(const map<int,vector<char>>& telephoneMap, 
              vector<string>&res, string digits, int level, string value) {
    if (level == digits.size()) {
         res.push_back(value);
    }
    vector<char> choices= telephoneMap[digits.at(level)];
    for(int i = 0 ; i < choices.size();++i) {
        value=value+choices[i];

    }

}

// this problem makes me think of the permutation problems. seems i have some swap/sawp ideal in my head, but i dont
//</char>know how to use it here actually.
abc 输出 abc 所有的不同顺序的排列组合

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//**方法一：用 std::next_permutation（最简洁
int main() {
    string s = "abc";
    sort(s.begin(), s.end()); // 确保从最小字典序开始
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permute(string &s, int l, int r) {
    if (l == r) {
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; ++i) {
        swap(s[l], s[i]);        // 交换当前位置
        permute(s, l + 1, r);    // 递归处理后续
        swap(s[l], s[i]);        // 回溯
    }
}

int main() {
    string s = "abc";
    permute(s, 0, s.size() - 1);
    return 0;
}
