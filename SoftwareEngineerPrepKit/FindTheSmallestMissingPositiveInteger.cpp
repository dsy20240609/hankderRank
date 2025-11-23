#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSmallestMissingPositive' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY orderNumbers as parameter.
 */


//wrong version using two steps loop
void swap(vector<int> & orderNumbers, int index) {
    int indexNew=index;
    
    while( (indexNew >=0 && indexNew < orderNumbers.size()) && (!(orderNumbers[indexNew] <=0 || orderNumbers[indexNew] > orderNumbers.size()))) {
        int temp = orderNumbers[orderNumbers[indexNew]-1];
        orderNumbers[orderNumbers[indexNew]-1] = orderNumbers[indexNew];     
        indexNew = temp-1;
    }
    
    if (orderNumbers[indexNew] <= 0 || orderNumbers[indexNew] > orderNumbers.size()) {
        int temp = orderNumbers[orderNumbers[indexNew]-1];
        orderNumbers[orderNumbers[indexNew]-1] = orderNumbers[indexNew];
        orderNumbers[indexNew]=temp;
    }
}
int findSmallestMissingPositive(vector<int> orderNumbers) {
    if (orderNumbers.size() == 0) {
        return 1;
    }
    for(size_t i =0; i < orderNumbers.size();++i) {
        if(orderNumbers[i] == (i+1)) {
            continue;
        } else if (orderNumbers[i] <=0 || orderNumbers[i] > orderNumbers.size()) {
            continue;
        } else {
          swap(orderNumbers,i);      
        }  
    }
    for(size_t i = 0 ;i < orderNumbers.size();++i) {
       if(orderNumbers[i] != i+1) {
        return i+1;
       }
    }
    return orderNumbers.size()+1;
}


// correct version using one loop
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSmallestMissingPositive' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY orderNumbers as parameter.
 */

int findSmallestMissingPositive(vector<int> orderNumbers) {
    if (orderNumbers.size() == 0) {
        return 1;
    }
    int i =0;
    while(i < orderNumbers.size()) {
        if(orderNumbers[i] <=0 || orderNumbers[i] >orderNumbers.size()) {
            i++;
        } else if (orderNumbers[i] == i+1) {
            i++;
        } else if (orderNumbers[i] == orderNumbers[orderNumbers[i]-1]) {
            i++;
        } else {
            int temp = orderNumbers[orderNumbers[i]-1];
            orderNumbers[orderNumbers[i]-1] =orderNumbers[i];
            orderNumbers[i]=temp;
        }
    }
    for(size_t i =0 ; i < orderNumbers.size();++i) {
        if(orderNumbers[i] != (i+1)) {
            return (i+1);
        }
    }
    return orderNumbers.size()+1;// if every number is sit at number -1 position, then the missing number is number.size()+1
}


int main()
{
    string orderNumbers_count_temp;
    getline(cin, orderNumbers_count_temp);

    int orderNumbers_count = stoi(ltrim(rtrim(orderNumbers_count_temp)));

    vector<int> orderNumbers(orderNumbers_count);

    for (int i = 0; i < orderNumbers_count; i++) {
        string orderNumbers_item_temp;
        getline(cin, orderNumbers_item_temp);

        int orderNumbers_item = stoi(ltrim(rtrim(orderNumbers_item_temp)));

        orderNumbers[i] = orderNumbers_item;
    }

    int result = findSmallestMissingPositive(orderNumbers);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
