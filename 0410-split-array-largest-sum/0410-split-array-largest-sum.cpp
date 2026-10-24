class Solution {
public:
    bool isPossible(vector<int>& nums, int size , int mid, int k){
        int stud = 1 ;
        int bookSum = 0;
        for(int i = 0; i < size; i++){
            if(bookSum+nums[i]<= mid){
                bookSum+=nums[i];
            }
            else{
                stud++;
                if(stud>k || nums[i]>mid) return false;
                bookSum = nums[i];
            }
        }
            return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int size = nums.size();
        int sum = 0;
        for(int x: nums){
            sum+=x;
        }
        int s = 0;
        int e = sum;
        int mid = s + (e-s)/2;
        int ans;
        while(s<=e){
            if(isPossible(nums , size , mid , k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }

        return ans;
    }
};