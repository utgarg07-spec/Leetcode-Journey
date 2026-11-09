class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> v1;
        queue<int> v2;
        vector<int> v3;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) v1.push(nums[i]); 
            if(nums[i]<0) v2.push(nums[i]);
        }
        while(!v1.empty()||!v2.empty()){
            v3.push_back(v1.front());
            v1.pop();
            v3.push_back(v2.front());
            v2.pop();
        }
        return v3;
    }
};