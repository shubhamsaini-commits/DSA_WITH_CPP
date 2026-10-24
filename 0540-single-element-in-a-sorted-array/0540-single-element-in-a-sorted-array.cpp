class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // check first and end position
        if(nums.size() == 1) return nums[0];
        if(nums[0]!= nums[1]) return nums[0];
        else if(nums[nums.size()-1] != nums[nums.size()-2] ) return nums[nums.size()-1];

        int st = 0;
        int end = nums.size()-1;
        int mid = st+(end-st)/2;

        while(st<=end){
            if(nums[mid] == nums[mid-1]){
                if((mid-st+1)%2 !=0) end = mid-2;
                else st = mid+1;
            }
            
            else if(nums[mid] == nums[mid+1]){
                if((end-mid+1)%2 !=0) st = mid+2;
                else end = mid-1;
            }
            else return nums[mid];

            mid = st+(end-st)/2;
        }
        return nums[mid];
    }
};