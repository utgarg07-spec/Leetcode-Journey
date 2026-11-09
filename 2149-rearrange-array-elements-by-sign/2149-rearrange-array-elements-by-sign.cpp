class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) v1.emplace_back(nums[i]); 
            if(nums[i]<0) v2.emplace_back(nums[i]);
        }
        int i=0;
        while(i<v1.size()){
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
            i++;
        }
        return v3;
    }
};