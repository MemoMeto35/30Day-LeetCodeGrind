// Minimum Number of Pushes to Type Word II
// BruteForce
// time O(n); space O(1);
class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp; 
        for(int i = 0; i<word.size(); i++){
            mp[word[i]]++;
        }
        vector<pair<char,int>> pairs; 
        for(auto& it : mp){
            pairs.push_back(it);
        }
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        int pushes = 0;
        int i = 0;
        int j = 0; 
        while(i<pairs.size()){
            if(i%8==0) j++;
            pushes += pairs[i].second * j; 
            i++;
        }
        return pushes; 
    }
};
// better solution: Frequency table
// time: O(n), space: O(1) 
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0); // non-scalable data structure; 
        for(int i = 0; i<word.size(); i++){
            freq[word[i]-'a']++;
        } 
        sort(freq.rbegin(), freq.rend()); // sort accending
        int pushes =0, i = 0, j=0; 
        while(i<freq.size() && freq[i]>0){
            if(i%8==0) j++;
            pushes += freq[i]* j; 
            i++;
        }
        return pushes; 
    }
};
