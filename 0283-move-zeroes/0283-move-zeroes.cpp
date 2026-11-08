class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt++;
            if(nums[i]!=0){
                v.push_back(nums[i]);
            }
        }
        for(int i=0;i<cnt;i++){
            v.push_back(0);
        }
        nums=v;
    }
};