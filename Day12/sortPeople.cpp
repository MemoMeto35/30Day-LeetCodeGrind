class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        if(names.size()==1) return names; 
        vector<pair<int, string>> mergedArr;
        for(int i =0; i<heights.size(); i++){
            mergedArr.push_back(make_pair(heights[i], names[i]));
        }
        sort(mergedArr.begin(), mergedArr.end());
        vector<string> result; 
        for(int i = heights.size()-1; i>=0; i--){
            result.push_back(mergedArr[i].second);
        }
        return result; 


    }
};
