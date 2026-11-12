class Solution {
public:

long long combination(long long n,long long k){
    if (k<0||k>n) return 0;
    if (k==0||k==n) return 1;
    if (k> n/2) k=n-k;
    long long res = 1;
    for (long long i=1;i<=k;i++) {
        res = res*(n-i+1)/i;
    }
    return res;
}

    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if(rowIndex<0) return v;
        for(int i=0;i<=rowIndex;i++){
            if(i==0||i==rowIndex) v.push_back(1);
            else{
                v.push_back(combination(rowIndex,i));
            }
        }
        return v;
    }
};