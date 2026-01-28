class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
    bool bs(vector<int>& nums,int l, int r, int target){
        if(l > r){
            return false;
        }
        int mid = (l+r)/2;
        if(nums[mid] == target){
            return true;
        }
        // Case 1: The right half is definitely sorted
        if(nums[mid] < nums[l]){
            if(target <= nums[r] && target >= nums[mid]){
                return bs(nums,mid+1,r,target);
            }
            else{
                return bs(nums,l,mid-1,target);
            }
        }
        // Case 2: The left half is definitely sorted
        else if(nums[mid] > nums[r]){
            if(target >= nums[l] && target <= nums[mid]){
                return bs(nums,l,mid-1,target);
            }
            else{
                return bs(nums,mid+1,r,target);
            }
        }
        // Case 3: Ambiguity due to duplicates (nums[l] == nums[mid] == nums[r])
        else{
            bool left = bs(nums,l,mid-1,target);
            bool right = bs(nums,mid+1,r,target);
            return left || right;
        }
    }
};