#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



#include <stack>
#include <sstream>
/*
 * Complete the 'processCouponStackOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minStack;

public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minStack.top())
            minStack.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }

    bool empty() {
        return s.empty();
    }
};

vector<int> processCouponStackOperations(vector<string> operations) {
    MinStack s;
    vector<int> res;
    if(operations.empty()) {return res;}
    
    for(size_t i =0; i < operations.size();++i) {
        string temp = operations[i];
        vector<string> command;
        istringstream iss(temp);
        string word;
        while(iss>> word) {
            command.push_back(word);
        }

        if(command.size() == 2) {
            if(command[0] == "push") {
                s.push(std::stoi(command[1]));
            } 
        } else if (command.size() == 1) {
            if (command[0] == "pop") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (command[0] == "top") {
                if (!s.empty()) {
                    res.push_back(s.top());
                }
            } else if (command[0] == "getMin") {
                if (!s.empty()) {
                    res.push_back(s.getMin());          
                }
            }
        }
    }
        return res;
}
