class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                start = mid + 1;   // finds last occurrence
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        if (res == -1) return {-1, -1};

        int first = res;
        int last = res;

        while (first - 1 >= 0 && nums[first - 1] == target)
            first--;

        while (last + 1 < nums.size() && nums[last + 1] == target)
            last++;

        return {first, last};
    }
};