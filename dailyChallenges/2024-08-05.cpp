// mySolution, time: O(n)
// space: O(n)
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hash; 
        for(int i = 0; i<arr.size(); i++){
            hash[arr[i]]++;
        }
        for(int i = 0; i<arr.size(); i++){
            if(hash[arr[i]]==1) k--;
            if(k==0) return arr[i];
        }
        return "";

    }
};

// Brute Force time: O(n^2), space O(n);
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> distinctStrings;
        // Iterate through each string in the array
        for (int i = 0; i < n; i++) {
            string currentString = arr[i];
            bool isDistinct = true;
            // Check if the current string is distinct
            for (int j = 0; j < n; j++) {
                if (j == i) continue;  // Skip comparing with itself
                if (arr[j] == currentString) {
                    isDistinct = false;
                    break;
                }
            }
            // If the string is distinct, add it to the vector
            if (isDistinct) {
                distinctStrings.push_back(currentString);
            }
        }
        // Check if there are enough distinct strings
        if (distinctStrings.size() < k) {
            return "";
        }
        return distinctStrings[k - 1];
    }
};
// Hash Set, time: O(n) space: O(n) 
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinctStrings;
        unordered_set<string> duplicateStrings;
        // First pass: Identify distinct and duplicate strings
        for (auto& str : arr) {
            // If the string is already in duplicateStrings, skip further
            // processing
            if (duplicateStrings.count(str)) {
                continue;
            }
            // If the string is in distinctStrings, it means we have seen it
            // before, so move it to duplicateStrings
            if (distinctStrings.count(str)) {
                distinctStrings.erase(str);
                duplicateStrings.insert(str);
            } else {
                distinctStrings.insert(str);
            }
        }
        // Second pass: Find the k-th distinct string
        for (auto& str : arr) {
            if (!duplicateStrings.count(str)) {
                // Decrement k for each distinct string encountered
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }
        return "";
    }
};
// Optimal: frequency map; 
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequencyMap;

        // First pass: Populate the frequency map
        for (string& str : arr) {
            frequencyMap[str]++;
        }

        // Second pass: Find the k-th distinct string
        for (string& str : arr) {
            // Check if the current string is distinct
            if (frequencyMap[str] == 1) {
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }
      
        return "";
    }
};
