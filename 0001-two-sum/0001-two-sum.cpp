class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n=nums.size();
        if(n==0) return v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int temp = target - nums[i];
            auto it = m.find(temp);
            if(it!=m.end()){
                v.push_back(it->second);
                v.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return v;
    }
};