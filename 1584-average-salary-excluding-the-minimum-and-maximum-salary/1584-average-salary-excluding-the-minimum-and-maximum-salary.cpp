class Solution {
public:
    double average(vector<int>& salary) {
        double n = salary.size();
        //sort(salary.begin(),salary.end());
        double sum = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<salary.size();i++){
            if(salary[i]<min) min=salary[i];
            if(salary[i]>max) max=salary[i];
            sum+=salary[i];
        }
        return (sum-max-min)/(n-2);
    }
};