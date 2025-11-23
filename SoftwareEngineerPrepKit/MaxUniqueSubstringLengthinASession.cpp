#include <bits/stdc++.h>

using namespace std;


#include <algorithm>
/*
 * Complete the 'maxDistinctSubstringLengthInSessions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING sessionString as parameter.
 */



int maxDistinctSubstringLengthInSessions(string sessionString) {

    if(sessionString.size() <=1) {
        return sessionString.size();
    }

    auto removeSmaller = [](map<char,int>& mp, char t) {
    int base = mp[t];
    for (auto it = mp.begin(); it != mp.end(); ) {
        if (it->second <= base)
            it = mp.erase(it);
        else
            ++it;
    }
    };
    map<char,int> m;
    m.insert(make_pair(sessionString[0],0));
    int i =0;
    int j=1;
    int maxSize=1;

    while(j < static_cast<int>(sessionString.size())) {
        auto it = m.find(sessionString[j]);
        if(it != m.end()) {
          i = (it->second)+1;
          removeSmaller(m,it->first);
          m.insert(make_pair(sessionString[j],j));
          maxSize = std::max(maxSize,static_cast<int>(m.size()));
          j++;
        } else {
          m.insert(make_pair(sessionString[j], j));
          maxSize = std::max(maxSize,static_cast<int>(m.size()));
          j++;
        }
    }
    return maxSize;
}

int main()
{
    string sessionString;
    getline(cin, sessionString);

    int result = maxDistinctSubstringLengthInSessions(sessionString);

    cout << result << "\n";

    return 0;
}


// correct solution for * for several sessions
#include <bits/stdc++.h>

using namespace std;


#include <algorithm>
/*
 * Complete the 'maxDistinctSubstringLengthInSessions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING sessionString as parameter.
 */



int maxDistinctSubstringLengthInSessions(string sessionString) {

    int n = sessionString.size();
    int result = 0;

    // sliding window within each session
    vector<int> last(26, -1);  // last occurrence of each character
    int left = 0;              // left pointer of sliding window

    for (int right = 0; right < n; right++) {
        char c = sessionString[right];

        if (c == '*') {
            // session ends: reset sliding window and last occurrences
            left = right + 1;
            fill(last.begin(), last.end(), -1);
            continue;
        }

        int idx = c - 'a';

        // if this char appeared inside the current window
        if (last[idx] >= left) {
            left = last[idx] + 1;   // shrink window
        }

        last[idx] = right;          // update last occurrence
        result = max(result, right - left + 1);
    }

    return result;
}

int main()
{
    string sessionString;
    getline(cin, sessionString);

    int result = maxDistinctSubstringLengthInSessions(sessionString);

    cout << result << "\n";

    return 0;
}
