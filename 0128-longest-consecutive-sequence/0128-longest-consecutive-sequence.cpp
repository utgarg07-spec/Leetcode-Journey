class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
    sort(nums.begin(),nums.end());
    int cnt=1;
    int temp=1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            continue;
        }
        if(nums[i]+1==nums[i+1]){
            temp++;
            cnt = max(cnt,temp);
        }
        else{
            temp=1;
        }
    }
    return cnt;
    }
};