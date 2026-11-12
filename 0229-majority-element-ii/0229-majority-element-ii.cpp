class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> m;
        int n = nums.size();
        if(n==0) return v;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(const auto& it: m){
            if(it.second > (n/3)){
                v.push_back(it.first);
            }
        }
        return v;
    }
};