class Solution {
public:
    int addDigits(int num) {
         while(num >= 10){
            int sum = 0;
            for(int i = num; i > 0; i /= 10){
                int lastdigit = i % 10;
                sum += lastdigit;
            }
            num = sum;
        }
        return num;
    }
};
