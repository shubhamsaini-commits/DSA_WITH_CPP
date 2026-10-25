class Solution {
public:
    bool isPossible(vector<int>& position, int mid, int m){
        int lastPos=position[0];
        int balls = 1;
        int size = position.size();
        for(int i = 0; i < size; i++){
            if(position[i]-lastPos>=mid){
                balls++;
                if(balls == m) return true;
                lastPos=position[i];
            }
           
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());
        int currMax = 0;
        int st = 0;
        for(int x: position){
            currMax = max(currMax , x);
        }
        int end = currMax;
        int mid = st + (end-st)/2;
        int ans;
        while(st<=end){
            if(isPossible(position, mid,m)){
                ans = mid;
                st = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = st + (end-st)/2;
        }
        return ans;
    }
};