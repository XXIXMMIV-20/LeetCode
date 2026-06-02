class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> hashmap;
        hashmap[0] = 1;
        int PrefixSum = 0 , Count = 0;
        for(int i = 0; i < nums.size(); i++){
            PrefixSum += nums[i];
            int remaining = PrefixSum - k;
            Count += hashmap[remaining];
            hashmap[PrefixSum] += 1;
        }
        return Count;
    }
};
