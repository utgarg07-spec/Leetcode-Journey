class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k=k%n;
        vector<int> v;
        for(int i=n-k;i<n;i++){
            v.push_back(arr[i]);
        }
        for(int i=0;i<n-k;i++){
            v.push_back(arr[i]);
        }
        arr =v;
    }
};