class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return;
        int c0=0;
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==2) c2++;
            if(nums[i]==1) c1++;
            if(nums[i]==0) c0++;
        }
        nums.clear();
        for(int i=0;i<c0;i++){
            nums.push_back(0);
        }
        for(int i=0;i<c1;i++){
            nums.push_back(1);
        }
        for(int i=0;i<c2;i++){
            nums.push_back(2);
        }
        return ;
    }
};