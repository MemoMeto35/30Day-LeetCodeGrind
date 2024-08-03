// using hash
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hash; 
        for(int i = 0; i<arr.size(); i++){
            if(hash.find(arr[i])==hash.end()){
            hash[arr[i]]=1;}
            else{hash[arr[i]]++;}
        }
        for(int i = 0; i<arr.size(); i++){
            if(hash.find(target[i])!=hash.end() && hash[target[i]]!=0){
                hash[target[i]]--;
                continue;
            }else{return false;}
        }
        return true;
    }
// using sorting

    bool canBeEqualUsingSorting(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i< arr.size(); i++){
            if(target[i]!=arr[i]) return false; 
        }
        return true; 

    }
};
