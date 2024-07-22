class Solution {
public:
    int romanToInt(string s) {
            unordered_map<char, int> hash; 
        hash = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='I' && s[i+1] == 'V') {ans+=4; i++; continue;}
            if(s[i]=='I' && s[i+1] == 'X') {ans+=9; i++; continue;}
            if(s[i]=='X' && s[i+1] == 'L') {ans+=40; i++; continue;}
            if(s[i]=='X' && s[i+1] == 'C') {ans+=90; i++; continue;}
            if(s[i]=='C' && s[i+1] == 'D') {ans+=400; i++; continue;}
            if(s[i]=='C' && s[i+1] == 'M') {ans+=900; i++; continue;}

            ans += hash[s[i]];

        }
        return ans; 

        
    }
};
