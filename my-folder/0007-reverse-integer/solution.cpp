class Solution {
public:
    int reverse(long x) {
        long reverse_no = 0;
        bool neg = x < 0;
        x = abs(x);
        while(x > 0){
            reverse_no = reverse_no * 10 + (x % 10);
            x = x / 10;
            if (reverse_no > INT_MAX || (neg && reverse_no > (long long) INT_MAX + 1)){
                return 0;
            }
        }
        return neg ? -reverse_no : reverse_no;
    }
};
