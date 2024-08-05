class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n, 1);
        if (n<=2) return 0;
        arr[1]=0;
        int k = 0;
        while(k<n){
            arr[k] = 0;
            k+= 2;
        }
        arr[2]=1;
        for(int i = 3; i<n; i++){
            if(i*i>n) break;
            for(int j = i*i; j<n; j+=i){
                if(j%i==0) arr[j] =0;
            }
        }
        int res = accumulate(arr.begin(), arr.end(), 0);
        return res; 
    }
};
