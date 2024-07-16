class Solution {
public:
    string buildString(string str){
        vector<char> newString;
        for(int i =0; i<str.size(); i++){
            if(str[i] != '#'){
                newString.push_back(str[i]);
            }
            else{
                if(newString.size()) newString.pop_back();
            }
        }
        newString.push_back('\0');
        char str2[newString.size()];
        
        for(int i = 0; i<newString.size(); i++){
            str2[i] = newString[i];

        }
        return str2; 
    }
    bool backspaceCompare(string s, string t) {
        string finalS = buildString(s);
        string finalT = buildString(t);

        if(finalS.size() != finalT.size()) return false;
        for(int i =0; i< finalS.size(); i++){
            if(finalS[i] != finalT[i]) return false;
        }
        return true;
    }
};
