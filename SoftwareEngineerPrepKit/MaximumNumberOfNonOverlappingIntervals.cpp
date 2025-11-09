#include <algorithm>
#include <vector>
#include <iostream>

/*
 * Complete the 'maximizeNonOverlappingMeetings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY meetings as parameter.
 */

int maximizeNonOverlappingMeetings(vector<vector<int>> meetings) {
    if(meetings.size() <=1) {
        return meetings.size();
    }
    std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];  
    });
    
    int count=1;
    int preEnd=meetings[0][1];
    for(size_t i = 1; i < meetings.size();++i) {
        if(meetings[i][0] >= preEnd) {
          count++;
          preEnd=meetings[i][1];
       } 
    }
    return count;
}