class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        int pos=0;
        int neg=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                v[2*pos]=nums[i];
                pos++;
            }
            if(nums[i]<0){
                v[2*neg-1]=nums[i];
                neg++;
            }
        }
        return v;
    }
};