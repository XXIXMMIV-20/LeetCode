class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1){
            if(st.count(n)) return false;
            st.insert(n);
            int sum = 0;
            for(int i = n; i > 0; i /= 10){
                int lastdigit = i % 10;
                sum += lastdigit * lastdigit;
            }
            n = sum;
        }
        return true;
    }
};
