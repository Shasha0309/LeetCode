class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m1 = m-1;
        int n1 = n-1;
        int tot = m+n-1;
        while(n1>=0){
            if(m1>=0 && nums1[m1]>nums2[n1]){
                nums1[tot] = nums1[m1];
                m1--;
            }
            else{
                nums1[tot] = nums2[n1];
                n1--;
            }
            tot--;
        }
    }
};