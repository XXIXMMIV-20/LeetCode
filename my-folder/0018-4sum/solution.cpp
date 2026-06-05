class Solution {
public:
    void merge(vector<int>& nums , int low , int mid , int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int>& nums , int low , int high){
        if(low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(nums , low , mid);
        mergeSort(nums , mid + 1 , high);
        merge(nums , low , mid , high);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        mergeSort(nums , 0 , n - 1);
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                        ans.push_back(temp);
                        k++; l--;
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};
