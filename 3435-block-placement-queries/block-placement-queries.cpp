
struct Node {
    int maxGap, leftmost, rightmost;
    Node() : maxGap(0), leftmost(-1), rightmost(-1) {}
    Node(int mg, int l, int r) : maxGap(mg), leftmost(l), rightmost(r) {}
};

Node merge(const Node& L, const Node& R) {
    Node res;
    res.leftmost  = (L.leftmost  != -1) ? L.leftmost  : R.leftmost;
    res.rightmost = (R.rightmost != -1) ? R.rightmost : L.rightmost;
    res.maxGap = max(L.maxGap, R.maxGap);
    if (L.rightmost != -1 && R.leftmost != -1)
        res.maxGap = max(res.maxGap, R.leftmost - L.rightmost);
    return res;
}

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n) : n(n), tree(4 * n) {}

    void update(int node, int l, int r, int pos) {
        if (l == r) {
            tree[node] = Node(0, pos, pos);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*node, l, mid, pos);
        else            update(2*node+1, mid+1, r, pos);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql > qr) return Node();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2*node, l, mid, ql, qr);
        if (ql > mid)  return query(2*node+1, mid+1, r, ql, qr);
        return merge(query(2*node, l, mid, ql, mid),
                     query(2*node+1, mid+1, r, mid+1, qr));
    }

    void update(int pos)           { update(1, 0, n-1, pos); }
    Node query(int ql, int qr)     { return query(1, 0, n-1, ql, qr); }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxX = 0;
        for (auto& q : queries)
            maxX = max(maxX, q[1]);

        SegTree seg(maxX + 1);
        seg.update(0);  // origin is always a boundary

        vector<bool> results;

        for (auto& q : queries) {
            if (q[0] == 1) {
                seg.update(q[1]);
            } else {
                int x = q[1], sz = q[2];
                Node res = seg.query(0, x);
                // max gap between consecutive obstacles in [0, x]
                int best = res.maxGap;
                // gap between last obstacle before x and x itself
                if (res.rightmost != -1)
                    best = max(best, x - res.rightmost);
                results.push_back(best >= sz);
            }
        }
        return results;
    }
};