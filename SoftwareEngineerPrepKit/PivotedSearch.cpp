int searchRotatedTimestamps(vector<int> nums, int target) {
    int left =0;
    int right = nums.size();
    if (nums.empty()) {return -1;}
    while(left <= right) {
        int mid = left+(right-left)/2;
        if(nums[mid] == target) {
            return mid;
        } else if ( nums[left] <= nums[mid]) {// left half is sorted
            if (target > nums[mid] || target <= nums[right]) {
                left=mid+1;
            } else {
                right=mid-1;
            }
        } else  {// right is sorted 
             if (target>=nums[left] || target <nums[mid]) {
                    right=mid-1;
                } else {
                    left=mid+1;
                }
        }
    }
    if(left < nums.size() && nums[left] == target) {return left;}
    if(right >=0 && nums[right] == target) {return  right;}
    return -1;
}