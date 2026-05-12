class Solution {
public:
    bool check(int l , int r , string &s){
        if(l >= r) return true;
        if(!isalnum(s[l])) return check(l + 1 , r , s);
        if(!isalnum(s[r])) return check(l , r - 1 , s);
        if(tolower(s[l]) != tolower(s[r])) return false;
        return check(l + 1 , r - 1 , s);
    }
    bool isPalindrome(string s) {
        return check(0 , s.size() - 1 , s);
    }
};
