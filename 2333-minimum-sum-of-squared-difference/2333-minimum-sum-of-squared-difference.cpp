class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> diff(nums1.size());
        int mx = 0;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k) high = mid;
            else low = mid + 1;
        }

        int limit = low;
        long long ans = 0;

        for (int d : diff) {
            int reduced = min(d, limit);
            ans += 1LL * reduced * reduced;
            if (d > limit) k -= d - limit;
        }

        for (int d : diff) {
            if (k == 0) break;
            if (d >= limit && d > 0) {
                ans -= 1LL * limit * limit;
                ans += 1LL * (limit - 1) * (limit - 1);
                k--;
            }
        }

        return ans;
    }
};