int findFirstOccurrence(vector<int> nums, int target) {
    if (nums.size() ==0) {
        return -1;
    }
    int left=0;
    int right=nums.size()-1;
    while(left < right) {
        int mid = left + (right-left)/2;
        if (target == nums[mid]) {
            right=mid;
        } else if (target < nums[mid]) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if (left < nums.size()) {
      if (nums[left] == target) {
        return left;
      } 
    }
    if (right >=0) {
      if (nums[right] == target) {
        return right;
      }
    }
    return -1;
}
