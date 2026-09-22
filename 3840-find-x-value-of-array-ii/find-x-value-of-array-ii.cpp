class Solution {
public:
    struct Node {
        int whole = 1;
        long long pref[5] = {};
        long long suff[5] = {};
    };

    int k;

    Node mergeNode(const Node& a, const Node& b) {
        Node c;

        // Product of the complete segment
        c.whole = (a.whole * b.whole) % k;

        // Prefixes:
        // 1. Prefix entirely inside left
        // 2. Entire left + prefix of right
        for (int r = 0; r < k; r++) {
            c.pref[r] += a.pref[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (a.whole * r) % k;
            c.pref[nr] += b.pref[r];
        }

        // Suffixes:
        // 1. Suffix entirely inside right
        // 2. Suffix of left + entire right
        for (int r = 0; r < k; r++) {
            c.suff[r] += b.suff[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (r * b.whole) % k;
            c.suff[nr] += a.suff[r];
        }

        return c;
    }

    vector<Node> tree;

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].whole = rem;
            tree[node].pref[rem] = 1;
            tree[node].suff[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = mergeNode(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = Node();

            int rem = val % k;

            tree[node].whole = rem;
            tree[node].pref[rem] = 1;
            tree[node].suff[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, val);
        }

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update for future queries
            update(1, 0, n - 1, index, value);

            // Remaining array = [start ... n-1]
            Node res = query(1, 0, n - 1,
                             start, n - 1);

            // Every non-empty prefix corresponds
            // to exactly one possible suffix removal.
            ans.push_back((int)res.pref[x]);
        }

        return ans;
    }
};