#include<bits/stdc++.h>
using namespace std;
using i8 = signed char;
using u8 = unsigned char;
 
using i16 = short;
using u16 = unsigned short;
 
using i64 = long long;
using u64 = unsigned long long;
 
using i128 = __int128_t;
using u128 = __uint128_t;
#define pii pair<int, int>
const int N = 1e5;
const int M = 1e6;
const int INF = 1e9;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); //64位哈希种子

template<class Info>
struct SegmentTree {
    int n;
    std::vector<i64> tag;
    std::vector<Info> info;
    SegmentTree(int n_) : n(n_), info(4 * n) {}

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }


    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

    void build(int p, int l, int r, const std::vector<i64> &a) {
        if (r - l == 1) {
            info[p] = Info(a[l]); // 叶子节点
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m, a);
        build(2 * p + 1, m, r, a);
        pull(p);
    }

    void build(const std::vector<i64> &a) {
        build(1, 0, n, a);
    }
};

struct Info {
    i64 sum = 0;
    int len = 0;
    Info() : len(0), sum(-INF) {}
    Info(i64 x) : len(1), sum(x) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.len = a.len + b.len;
    return c;
}

void solve()
{
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
}