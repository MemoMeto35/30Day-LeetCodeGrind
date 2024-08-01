// My solution
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size(); 
        int ans = 0;
        for(int i = 0; i < n; i++){
            int age = (details[i][11]-'0')*10+(details[i][12]-'0');
            if(age > 60) ans++;
        }
        return ans; 
    }
};
// A more elegant Solution
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto info: details)
            if (stoi(info.substr(11, 2)) > 60) res++;

        return res;
    }
};
