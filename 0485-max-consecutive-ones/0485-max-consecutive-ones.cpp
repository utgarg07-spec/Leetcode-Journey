class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        long long a =0;
        long long cnt=0;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt ++;
            }
            if(a<cnt){
                a=cnt;
            }
            if(nums[i]==0){
                cnt=0;
            }
        }
        return a;
    }
};