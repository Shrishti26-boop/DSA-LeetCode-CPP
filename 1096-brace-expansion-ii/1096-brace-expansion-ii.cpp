class Solution {
public:
    string s;
    int pos;

    set<string> merge(set<string> a, set<string> b) {
        set<string> res;

        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> solve() {
        set<string> res;
        set<string> cur;

        while (pos < s.size() && s[pos] != '}') {

            if (s[pos] == ',') {
                for (auto &x : cur)
                    res.insert(x);

                cur.clear();
                pos++;
            }
            else {
                set<string> part;

                if (s[pos] == '{') {
                    pos++;
                    part = solve();
                    pos++;
                }
                else {
                    part.insert(string(1, s[pos]));
                    pos++;
                }

                if (cur.empty())
                    cur = part;
                else
                    cur = merge(cur, part);
            }
        }

        for (auto &x : cur)
            res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = solve();

        return vector<string>(ans.begin(), ans.end());
    }
};