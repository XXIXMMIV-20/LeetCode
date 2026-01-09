class Solution {
public:
    bool isPalindrome(long x) {
        if (x < 0) return false;
        long original = x , reverse_no = 0 ;
        while(x > 0){
            reverse_no = (reverse_no * 10) + (x % 10);
            x = x / 10;
        }
        if(reverse_no == original) return true;
        else return false;
    }
};
