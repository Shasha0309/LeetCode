class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n+m;
        int ind1 = total/2;
        int ind2 = ind1-1;
        int i=0;
        int j=0;
        int count = 0;
        int indle1 = -1;
        int indle2 = -1;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(count==ind1){ indle1 = nums1[i];}
                if(count==ind2){ indle2 = nums1[i];}
                count++;
                i++;
            }
            else{
                if(count==ind1){ indle1 = nums2[j];}
                if(count==ind2){ indle2 = nums2[j];}
                count++;
                j++;
            }
        }
        while(i<n){
            if(count==ind1){ indle1 = nums1[i];}
                if(count==ind2){ indle2 = nums1[i];}
                count++;
                i++;
        }
        while(j<m){
             if(count==ind1){ indle1 = nums2[j];}
                if(count==ind2){ indle2 = nums2[j];}
                count++;
                j++;
        }
        if(total%2==1) return (double)indle1;
        return (double)((double)(indle1+indle2))/2.0; 
    }
};