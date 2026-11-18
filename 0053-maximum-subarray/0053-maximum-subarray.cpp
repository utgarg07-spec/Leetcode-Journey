class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        long long temp =0;
        long long sum = nums[0];
        for(int i=0;i<n;i++){
           temp+=nums[i];
            if(nums[i]>temp) temp=nums[i];
            if(temp>sum) sum = temp;
            
        }
        sum=max(temp,sum);
        return sum;
    }
};