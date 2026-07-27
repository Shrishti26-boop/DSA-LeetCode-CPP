class Solution {
public:
    long long maxProduct(vector<int>& nums) {
       long long max1=LLONG_MIN;
       long long max2=LLONG_MIN;
       long long min1=LLONG_MAX;
       long long min2=LLONG_MAX;
       for(int x:nums){
        if(x>=max1){
            max2=max1;
            max1=x;
        }
        else if(x>max2){
            max2=x;
        }
        if(x<=min1){
            min2=min1;
            min1=x;
        }
        else if(x<min2){
            min2=x;
        }
       }
        long long maxpair=max(max1*max2,min1*min2);
        long long minpair=max1*min1;
       
      return max(maxpair*100000,minpair*-100000);
    }
};