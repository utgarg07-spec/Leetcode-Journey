class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int cnt=1;
        
        for(const auto& x:s){
           
            if(s.find(x-1)==s.end()){
                int temp=1;
                int it = x;
                while(s.find(it+1)!=s.end()){
                    it = it+1;
                    temp++;
                }
                cnt = max(temp,cnt);
            }
        }
        return cnt;
    }
};