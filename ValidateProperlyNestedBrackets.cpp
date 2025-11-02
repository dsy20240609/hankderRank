#include <bits/stdc++.h>

using namespace std;



#include <stack>
/*
 * Complete the 'areBracketsProperlyMatched' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code_snippet as parameter.
 */

bool areBracketsProperlyMatched(string code_snippet) {
    if (code_snippet.empty()) {return true;}
    stack<char> s;
    for(size_t i = 0 ; i < code_snippet.length();++i) {
        if (code_snippet.at(i) == '(' ||
            code_snippet.at(i) == '{' ||
            code_snippet.at(i) == '[') {
                s.push(code_snippet.at(i));
        } else if (code_snippet.at(i) == ')') {
            if (s.empty()) {return false;}
            if (s.top() == '(') {
                s.pop();
                continue;
            } else {
                return false;
            }
        } else if (code_snippet.at(i) == '}') {
            if (s.empty()) {return false;}
            if(s.top() == '{') {
                s.pop();
                continue;
            } else {
                return false;
            }
        } else if (code_snippet.at(i) == ']') {
            if (s.empty()) {return false;}
            if(s.top() == '[') {
                s.pop();
                continue;
            } else {
                return false;
            }
        }
    }
    return s.empty();
}
