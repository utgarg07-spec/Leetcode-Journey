class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> m;
        int n = nums.size();
        if(n==0) return v;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>(n/3)&&(find(v.begin(), v.end(), nums[i]) == v.end())){
                v.push_back(nums[i]);
            }
        }
       
        return v;
    }
};