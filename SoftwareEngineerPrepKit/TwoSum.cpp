// based on the explaination of example, it means that two levels of loop O(n2) solution
vector<int> findTaskPairForSlot(vector<int> taskDurations, int slotLength) {
    if(taskDurations.size() <=1) {return [-1,-1];}
    vector<int> pair=[-1,-1];
    for(int i=0;i < taskDurations.size()-1;++i) {
        for(int j=i+1; j < taskDurations.size();++j) {
            if(taskDurations[i]+taskDurations[j] == slotLength) {
                pair[0]=i;
                pair[1]=j;
                return pair;
            }
        }
    }
    return pair;
}
//I was able to solve, but for test case 7 and 8, if you don't solve it in O(n) it will fail.

vector<int> twoSum(const vector<int>& taskDurations, int slotLength) {
    unordered_map<int, int> seen; // <值, 索引>
    for (int i = 0; i < (int)taskDurations.size(); ++i) {
        int need = slotLength - taskDurations[i];
        if (seen.count(need)) {
            return {seen[need], i};
        }
        seen[taskDurations[i]] = i;
    }
    return {-1, -1};
}