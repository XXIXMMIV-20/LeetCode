class Solution {
public:
    int Waviness(int x){
        vector<int> digits;
        int count = 0;
        while(x > 0){
            digits.push_back(x % 10);
            x /= 10;
        }
        if(digits.size() < 3) return 0;
        for(int i = 1; i < digits.size() - 1; i++){
            if(digits[i] > digits[i - 1] && digits[i] > digits[i + 1] || digits[i] < digits[i - 1] && digits[i] < digits[i + 1]) count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            ans += Waviness(i);
        }
        return ans;
    }
};
