#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> res;
    stringstream ss(str);
    string temp;
    while(getline(ss,temp,',')) {
        res.push_back(std::stoi(temp));
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}