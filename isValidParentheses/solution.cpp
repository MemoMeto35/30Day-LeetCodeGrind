class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true; 
        vector<char> stack; 
        unordered_map<char, char> hash; 
        hash['('] = ')';
        hash['{'] = '}';
        hash['['] = ']';

        for(int i  = 0; i<s.size(); i++){
            if(hash.find(s[i]) != hash.end()){
                stack.push_back(s[i]);
            }
            else{
                if(stack.size()==0) return false;
                char leftBracket = stack.back();
                stack.pop_back();
                char correctBracket = hash[leftBracket];


                if(s[i] != correctBracket) return false; 
            }
        }
        
        return stack.size() == 0;

    }
};
