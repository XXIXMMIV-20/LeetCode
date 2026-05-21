class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evendigitnumcount = 0;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int count = (int)log10(nums[i]) + 1;
            if(count % 2 == 0) evendigitnumcount ++;
        }
        return evendigitnumcount;
    }
};
