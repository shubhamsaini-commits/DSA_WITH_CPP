class Solution {
public:
    bool isPossible(const vector<int>& position, int mid, int m) {
        int lastPos = position[0];
        int balls = 1;
        int size = position.size();
        
        // Start from i = 1 since the first ball is already at position[0]
        for (int i = 1; i < size; i++) {
            if (position[i] - lastPos >= mid) {
                balls++;
                if (balls == m) return true;
                lastPos = position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int st = 1;
        // Tightest mathematically possible upper bound
        int end = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(position, mid, m)) {
                ans = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};