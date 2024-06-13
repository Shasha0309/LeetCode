class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //int i = 0;
        int len = nums1.size();
        int end_ind = len-1;
        int j=0;
        if(n==0) return;
        while(m>0 && n>0){
           // if(nums1[m-1]<=nums2[n-1]){
                nums1[end_ind] = nums2[n-1];
                n--;
            //}
            /*else{
                nums1[end_ind] = nums1[m-1];
                m--;
            }*/
            end_ind--;
        }
        while(n>0){
            nums1[end_ind] = nums2[n-1];
            end_ind--;
            n--;
        }
        sort(nums1.begin(),nums1.end());
    }
};