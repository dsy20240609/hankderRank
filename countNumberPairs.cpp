int countAffordablePairs(vector<int> prices, int budget) {
 int left =0;
 int right=prices.size()-1;
 int count =0;
 while(left < right) {
    if (prices[left] + prices[right] <= budget) {
        count+= (right-left);
        left++;
    } else {
        right--;
    }
 }
 return count;
}