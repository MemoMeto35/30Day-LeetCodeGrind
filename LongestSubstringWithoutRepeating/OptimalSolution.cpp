// O(N)
// O(N)
// Using the swipping window Technique

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1){return s.size();}
        int longest = 0; 
        int left = 0;
        unordered_map<char, int> hash; 
        for(int right = 0; right < s.size(); right++){
            char currentLetter = s[right];

            if(hash.find(currentLetter) != hash.end() && hash[currentLetter]>=left){
                left = hash[currentLetter]+1;
            }
            hash[currentLetter] = right; 
            longest = max(longest, right - left +1);

        }
        return longest; 

    }
};
