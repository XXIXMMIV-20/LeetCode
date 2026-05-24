class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int , int> hashmap;
        for(int i = 0; i < arr.size(); i++){
            hashmap[arr[i]]++;
        }
        int Luckynum = -1;
        for(auto it : hashmap){
            if(it.second == it.first)
                Luckynum = max(Luckynum , it.first);
            
        }
        return Luckynum;
    }
};
