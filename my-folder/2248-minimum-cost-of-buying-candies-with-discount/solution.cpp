class Solution {
public:
    void swap(int &a , int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    int partition(vector<int>& cost , int low , int high){
        int pivot = cost[low];
        int i = low;
        int j = high;
        while(i < j){
            while(i <= high - 1 && cost[i] >= pivot) 
                i++;
            while(j >= low + 1 && cost[j] < pivot)
                j--;
            if(i < j){
                swap(cost[i] , cost[j]);
            }
        }
        swap(cost[low] , cost[j]);
        return j;
    }
    void qs(vector<int>& cost , int low , int high){
        if(low < high){
            int pIndex = partition(cost , low , high);
            qs(cost , low , pIndex - 1);
            qs(cost , pIndex + 1 , high);
        }
    }
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        qs(cost , 0 , n - 1);
        int totalCost = 0;
        
        for(int i = n - 1; i >= 0; i--){
            if((i + 1) % 3 != 0)
                totalCost += cost[i];
        }
        return totalCost;
    }
};
