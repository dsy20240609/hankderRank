#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'mergeHighDefinitionIntervals' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY intervals as parameter.
 */

vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
 std::sort(intervals.begin(), intervals.end(),
           [](const std::vector<int>& a, const std::vector<int>& b) {
                  return a[0] < b[0];
        });
        vector<vector<int>> res;
        if(intervals.size() == 0) {
            return res;
        }
        res.push_back(intervals[0]);
        size_t k=1;
        while(k< intervals.size()) {
            if(intervals[k][0] > res[res.size()-1][1]) {
                res.push_back(intervals[k]);
                k++;
            } else {
                res[res.size()-1][1] = max(intervals[k][1], res[res.size()-1][1]); // tricky point you need to get the max number between this two
                k++;
            }
        }
        return res;
}
