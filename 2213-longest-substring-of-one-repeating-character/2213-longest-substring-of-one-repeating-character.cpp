class Solution {
public:

    struct Node {
        int leftLen;
        int rightLen;
        int maxLen;
        int len;
        char leftChar;
        char rightChar;

        Node() {
            leftLen = rightLen = maxLen = len = 0;
            leftChar = rightChar = '#';
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftLen = a.leftLen;
        res.rightLen = b.rightLen;

        res.maxLen = max(a.maxLen, b.maxLen);

        if (a.rightChar == b.leftChar) {
            res.maxLen = max(res.maxLen, a.rightLen + b.leftLen);

            if (a.leftLen == a.len) {
                res.leftLen = a.len + b.leftLen;
            }

            if (b.rightLen == b.len) {
                res.rightLen = b.len + a.rightLen;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node].len = 1;
            seg[node].leftLen = 1;
            seg[node].rightLen = 1;
            seg[node].maxLen = 1;
            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            seg[node].leftChar = ch;
            seg[node].rightChar = ch;
            seg[node].leftLen = 1;
            seg[node].rightLen = 1;
            seg[node].maxLen = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(seg[1].maxLen);
        }

        return ans;
    }
};