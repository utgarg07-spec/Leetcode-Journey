class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        if(n==0) return v;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0&&ele2!=nums[i]){
                ele1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0&&ele1!=nums[i]){
                ele2=nums[i];
                cnt2=1;
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
        }
        if(count1>(n/3)) v.push_back(ele1);
        if(count2>(n/3)) v.push_back(ele2);
        return v;
    }
};