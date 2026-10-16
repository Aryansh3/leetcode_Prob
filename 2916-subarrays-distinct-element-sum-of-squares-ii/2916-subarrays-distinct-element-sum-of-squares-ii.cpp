class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                sq[node] = (sq[node] + 2 * sum[node]
                          + (r - l + 1)) % MOD;

                sum[node] = (sum[node] + (r - l + 1)) % MOD;
                lazy[node]++;
                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node]) {
                long long v = lazy[node];

                sq[node * 2] = (sq[node * 2] + 2 * v * sum[node * 2]
                              + v * v * (mid - l + 1)) % MOD;
                sum[node * 2] = (sum[node * 2] + v * (mid - l + 1)) % MOD;
                lazy[node * 2] += v;

                sq[node * 2 + 1] = (sq[node * 2 + 1]
                    + 2 * v * sum[node * 2 + 1]
                    + v * v * (r - mid)) % MOD;
                sum[node * 2 + 1] = (sum[node * 2 + 1]
                    + v * (r - mid)) % MOD;
                lazy[node * 2 + 1] += v;

                lazy[node] = 0;
            }

            self(self, node * 2, l, mid, ql, qr);
            self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> long long {
            if (ql > r || qr < l) return 0;
            if (ql <= l && r <= qr) return sq[node];

            int mid = (l + r) / 2;

            if (lazy[node]) {
                long long v = lazy[node];

                sq[node * 2] = (sq[node * 2] + 2 * v * sum[node * 2]
                              + v * v * (mid - l + 1)) % MOD;
                sum[node * 2] = (sum[node * 2] + v * (mid - l + 1)) % MOD;
                lazy[node * 2] += v;

                sq[node * 2 + 1] = (sq[node * 2 + 1]
                    + 2 * v * sum[node * 2 + 1]
                    + v * v * (r - mid)) % MOD;
                sum[node * 2 + 1] = (sum[node * 2 + 1]
                    + v * (r - mid)) % MOD;
                lazy[node * 2 + 1] += v;

                lazy[node] = 0;
            }

            return (self(self, node * 2, l, mid, ql, qr)
                  + self(self, node * 2 + 1, mid + 1, r, ql, qr)) % MOD;
        };

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            update(update, 1, 0, n - 1, left, i);

            ans = (ans + query(query, 1, 0, n - 1, 0, i)) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};