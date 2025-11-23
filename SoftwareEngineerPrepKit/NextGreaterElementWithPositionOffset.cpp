#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findNextGreaterElementsWithDistance' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY readings as parameter.
 */

vector<vector<int>> findNextGreaterElementsWithDistance(vector<int> readings) {
    vector<vector<int>> res;
    for(size_t i = 0 ; i < readings.size();++i) {
        bool hasfound=false;
        for(size_t j=i+1; j < readings.size();++j) {
            if(readings[j] >readings[i]) {
                res.push_back({readings[j],static_cast<int>(j-i)});
                hasfound=true;
                break;
            } 
        }
        if(!hasfound) {
            res.push_back({-1,-1});
        }
    }
    return res;
}