class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // Tối ưu: Nếu số nhỏ nhất > 0 thì tổng không bao giờ bằng 0 được nữa
            if (nums[i] > 0) break; 
            // Bỏ qua phần tử trùng lặp cho i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    // Bỏ qua các phần tử trùng lặp cho j và k
                    while (j < k && nums[j] == nums[++j]);
                    while (j < k && nums[k] == nums[--k]);
                } 
                else if (sum < 0) j++;
                else k--;
            }
        }
        return res;
    }
};