class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<long,long> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans;
        for(const auto& x: m){
            if(x.second>nums.size()/2){
                ans = x.first;
            }
        }
        return ans;
    }
};