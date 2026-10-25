class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1) return;

        int i = 0;
        int j = 1;
        int size = nums.size();

        while(j<size && i<size){
            if(nums[i]==0){
                if(nums[j]!=0){
                    swap(nums[i], nums[j]);
                    i++;
                    j++;
                }
                else j++;
            }
            else {
                i++;
                j = i+1;
            }
        }
    }
};