class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        for(int i = 0; i < heights.size() - 1; i++){
            for(int j = 0; j < heights.size() - i - 1; j++){
                if(expected[j] > expected[j + 1]) swap(expected[j], expected[j + 1]);  
            }
        }
        int count = 0;
        for(int i = 0; i < heights.size(); i++) if(expected[i] != heights[i]) count++;
        return count;
    }
};
