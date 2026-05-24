class Solution {
public:
    int partition(vector<int>& sorted , int low , int high){
        int pivot = sorted[low];
        int i = low;
        int j = high;
        while(i < j){
            while(sorted[i] <= pivot && i <= high -1) i++;
            while(sorted[j] > pivot && j >= low + 1) j--;
            if(i < j){
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
        int temp = sorted[low];
        sorted[low] = sorted[j];
        sorted[j] = temp;
        return j;
    }
    void qs(vector<int>& sorted , int low , int high){
        if(low < high){
            int pIndex = partition(sorted , low , high);
            qs(sorted , low , pIndex - 1);
            qs(sorted , pIndex + 1 , high);
        }
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        qs(sorted , 0 , sorted.size() - 1);
        unordered_map<int , int> hashmap;
        for(int i = 0; i < sorted.size(); i++){
            if(hashmap.find(sorted[i]) == hashmap.end()){
                hashmap[sorted[i]] = i;
            }
        }
        vector<int> ans;
        for(int num : nums) {
            ans.push_back(hashmap[num]);
        }
        return ans;
    }
};
