class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int PrefixProduct = 1 , SuffixProduct = 1;
        int maxiProduct = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(PrefixProduct == 0) PrefixProduct = 1;
            if(SuffixProduct == 0) SuffixProduct = 1;
            PrefixProduct *= nums[i];
            SuffixProduct *= nums[n - i - 1];
            maxiProduct = max(maxiProduct , max(PrefixProduct , SuffixProduct));
        }
        return maxiProduct;
    }
};