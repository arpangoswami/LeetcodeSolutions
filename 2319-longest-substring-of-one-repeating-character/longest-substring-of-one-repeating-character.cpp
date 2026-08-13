/**
 * Segment Tree, currently recursive
 * 
 * @Data Data type of actual values
 * @Node Data type of what to store in segment tree nodes
 * 
 * Node must have a default constructor and a constructor Node(const Data &d)
 */
struct Node {
    char leftCh, rightCh;
    int len, prefLen, sufLen, maxLen;

    Node() : leftCh(0), rightCh(0), len(0), prefLen(0), sufLen(0), maxLen(0) {}
    Node(const char &c) : leftCh(c), rightCh(c), len(1), prefLen(1), sufLen(1), maxLen(1) {}
};
Node mergeFn(Node a, Node b) {
    if (a.len == 0) return b; // handle identity from empty side
    if (b.len == 0) return a;

    Node res;
    res.leftCh = a.leftCh;
    res.rightCh = b.rightCh;
    res.len = a.len + b.len;

    res.prefLen = a.prefLen;
    if (a.prefLen == a.len && a.rightCh == b.leftCh)
        res.prefLen += b.prefLen; // a is entirely one char and matches b's start

    res.sufLen = b.sufLen;
    if (b.sufLen == b.len && b.leftCh == a.rightCh)
        res.sufLen += a.sufLen; // b is entirely one char and matches a's end

    res.maxLen = max(a.maxLen, b.maxLen);
    if (a.rightCh == b.leftCh)
        res.maxLen = max(res.maxLen, a.sufLen + b.prefLen); // merge across the boundary

    return res;
}
template<typename Data, typename Node>
class SegTree
{
    int n;
    vector<Node> st;
    function<Node(Node, Node)> mergeFn;
public:
    SegTree() = default;
    SegTree(const vector<Data> &data, const function<Node(Node, Node)> &fn)
    {
        n = data.size();
        st = vector<Node>(4 * n);
        mergeFn = fn;
        build(data, 1, 0, n - 1);
    }
 
    Node query(int l, int r) { return queryImpl(l, r, 1, 0, n - 1); };
    void pointUpdate(int pos, const Data &val) { return pointUpdateImpl(pos, val, 1, 0, n - 1); }
 
private:
    void build(const vector<Data> &data, int v, int l, int r)
    {
        if (l == r)
            st[v] = data[l];
        else
        {
            int mid = (l + r) / 2;
            build(data, 2 * v, l, mid);
            build(data, 2 * v + 1, mid + 1, r);
            st[v] = mergeFn(st[v * 2], st[v * 2 + 1]);
        }
    }
 
    Node queryImpl(int l, int r, int v, int nL, int nR)
    {
        if (l > r) return Node{};
        if (nL == l && nR == r)
            return st[v];
      int mid = (nL + nR) / 2;
        return mergeFn(
            queryImpl(l, min(r, mid), 2 * v, nL, mid),
            queryImpl(max(l, mid + 1), r, 2 * v + 1, mid + 1, nR)
        );
    }
 
    void pointUpdateImpl(int pos, const Data &val, int v, int nL, int nR)
    {
        if (nL == nR)
        {
            st[v] = val;
            return;
        }
        int mid = (nL + nR) / 2;
        if (pos <= mid)
            pointUpdateImpl(pos, val, 2 * v, nL, mid);
        else
            pointUpdateImpl(pos, val, 2 * v + 1, mid + 1, nR);
        st[v] = mergeFn(st[2 * v], st[2 * v + 1]);
    }
};
//Declare like SegTree<int, int> st(arr, [](int a, int b) { return gcd(a, b); });


class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<char> data(s.begin(), s.end());
        SegTree<char, Node> st(data, mergeFn);
        vector<int> ans;
        for(int i=0;i<queryIndices.size();i++){
            st.pointUpdate(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.query(0, n-1).maxLen);
        }
        return ans;
    }
};