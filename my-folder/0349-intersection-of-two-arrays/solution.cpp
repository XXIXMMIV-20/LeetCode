class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        unordered_set<int> inter;
        for(int i = 0; i < nums1.size(); i++){
            hash.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            if(hash.count(nums2[i])) inter.insert(nums2[i]);
        }
        return vector<int>(inter.begin() , inter.end());
    }
};
