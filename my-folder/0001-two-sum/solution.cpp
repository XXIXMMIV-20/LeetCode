class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> hashmap;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int rem = target - num;
            if(hashmap.find(rem) != hashmap.end())
                return {hashmap[rem] , i};
            hashmap[num] = i;
        }
        return {-1 , -1};
    }
};
