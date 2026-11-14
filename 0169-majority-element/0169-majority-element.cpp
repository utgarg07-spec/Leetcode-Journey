class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int cnt=0;
        int ele;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(nums[i]==ele) cnt++;
            else cnt--;
        }
        return ele;
    }
};