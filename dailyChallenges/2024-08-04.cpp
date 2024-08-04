//Range Sum of Sorted Subarray Sums
// time: O(n^2 log(n)) because we iterate through all of the array twice and then sort them log n;
// space: O(n^2), we created an array with a size of n * (n + 1) / 2; 
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans; 
        for(int i = 0; i < n; i++){
            int sum = nums[i];
            ans.push_back(sum);
            for(int j=i; j<n; j++){
                if(j==i) continue;
                sum+=nums[j];
                ans.push_back(sum);
                
            }
        }
        long long mod = 1000000000+7;
        long long result = 0;
        sort(ans.begin(), ans.end());
        for(int i = left-1; i<right; i++){
            result = result%mod + ans[i];
        }
        
        int res = result % mod;
        return res;
    }
};
// A better optimized solution 
// time: O(n^2 *log n)
// space: O(n)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq; // create a priority queue with an assending order
        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        int ans = 0, mod = 1e9 + 7;
      // delete the smallest element which index is smaller than the left; 
        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();
            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (i >= left) ans = (ans + p.first) % mod;
            // If index is less than the last index, increment it and add its
            // value to the first pair value.
            if (p.second < n - 1) {
                p.first += nums[++p.second];
                pq.push(p);
            }
        }
        return ans;
    }
};

// Optimized Solution: Binary Search and Sliding Window
// i didn't understand this solution
// time: O(n log(sum))
// space: o(1)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            mod;
        // Ensure non-negative result
        return (result + mod) % mod;
    }

private:
    int mod = 1e9 + 7;
    // Helper function to count subarrays with sum <= target and their total
    // sum.
    pair<int, long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j) {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        auto [count, sum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return sum - left * (count - k);
    }
};
