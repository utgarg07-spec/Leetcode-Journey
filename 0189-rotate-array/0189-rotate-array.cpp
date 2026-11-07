class Solution {
public:
void reverseArr(vector<int>& arr,int i, int n){
    while(i<n){
        int temp = arr[i];
        arr[i]=arr[n];
        arr[n] = temp;
        i++;
        n--;
    }
}
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        if(n==0) return;
        k=k%n;
      if(n==1) return;
    reverseArr(arr,0,n-1);
    reverseArr(arr,0,k-1);
    reverseArr(arr,k,n-1);
    }
};