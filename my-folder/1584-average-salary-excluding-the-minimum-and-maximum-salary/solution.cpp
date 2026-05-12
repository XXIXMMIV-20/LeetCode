class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX , maxi = INT_MIN;
        double sum = 0 ;
        for(int i = 0 ; i < salary.size(); i++){
            sum += salary[i];
            mini = min(mini , salary[i]);
            maxi = max(maxi , salary[i]);
        }
        sum = sum - mini - maxi;
        return sum / (salary.size() - 2);
    }
};
