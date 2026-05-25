class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long largest = LLONG_MIN;
        long long slargest = LLONG_MIN;
        long long tlargest = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == largest || nums[i] == slargest || nums[i] == tlargest)
                continue;
            if(nums[i] > largest){
                tlargest = slargest;
                slargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > slargest){
                tlargest = slargest;
                slargest = nums[i];
            }
            else if(nums[i] > tlargest)
                tlargest = nums[i];
        }
        if(tlargest == LLONG_MIN) return largest;
        return tlargest;
    }
};
