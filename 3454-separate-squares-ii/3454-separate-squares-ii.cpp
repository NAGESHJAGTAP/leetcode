class Solution {
    struct Event {
        double y;
        int x1, x2, t;
    };

    struct SegTree {
        int n;
        vector<int> cnt;
        vector<double> len, xs;

        SegTree(vector<double>& xs) : xs(xs) {
            n = xs.size() - 1;
            cnt.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int v, int l, int r) {
            if (cnt[v] > 0) len[v] = xs[r] - xs[l];
            else if (l + 1 == r) len[v] = 0;
            else len[v] = len[v * 2] + len[v * 2 + 1];
        }

        void update(int v, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cnt[v] += val;
                pull(v, l, r);
                return;
            }
            int m = (l + r) / 2;
            update(v * 2, l, m, ql, qr, val);
            update(v * 2 + 1, m, r, ql, qr, val);
            pull(v, l, r);
        }

        void update(int l, int r, int v) {
            update(1, 0, n, l, r, v);
        }

        double query() {
            return len[1];
        }
    };

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<double> xs;
        vector<Event> ev;

        for (auto& s : squares) {
            xs.push_back(s[0]);
            xs.push_back(s[0] + s[2]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto id = [&](double x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        for (auto& s : squares) {
            int x1 = id(s[0]);
            int x2 = id(s[0] + s[2]);
            ev.push_back({(double)s[1], x1, x2, 1});
            ev.push_back({(double)(s[1] + s[2]), x1, x2, -1});
        }

        sort(ev.begin(), ev.end(), [](auto& a, auto& b) {
            return a.y < b.y;
        });

        SegTree st(xs);
        double total = 0, prev = ev[0].y;

        for (int i = 0; i < ev.size();) {
            double y = ev[i].y;
            total += st.query() * (y - prev);
            while (i < ev.size() && ev[i].y == y) {
                st.update(ev[i].x1, ev[i].x2, ev[i].t);
                i++;
            }
            prev = y;
        }

        double half = total / 2;
        st = SegTree(xs);
        prev = ev[0].y;
        double cur = 0;

        for (int i = 0; i < ev.size();) {
            double y = ev[i].y;
            double area = st.query() * (y - prev);
            if (cur + area >= half && st.query() > 0)
                return prev + (half - cur) / st.query();

            cur += area;
            while (i < ev.size() && ev[i].y == y) {
                st.update(ev[i].x1, ev[i].x2, ev[i].t);
                i++;
            }
            prev = y;
        }
        return prev;
    }
};


