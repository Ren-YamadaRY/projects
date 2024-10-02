#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using vvs = vector<vs>;
using pll = pair<ll, ll>;
using qll = queue<ll>; // push, front, pop, size, empty
using pqll = priority_queue<ll>; // push, top, pop, size, empty
using smallpqll = priority_queue<ll, vector<ll>, greater<ll>>;
using dqll = deque<ll>; // push_back, push_front, front, back, pop_front, pop_back, at, size, empty
using sll = stack<ll>; // push, top, pop, size, empty
using smint = modint998244353;
using lmint = modint1000000007;
using vsm = vector<smint>;
using vvsm = vector<vsm>;
using vlm = vector<lmint>;
using vvlm = vector<vlm>;

#define repi(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define repd(i, s, n) for (ll i = (s); i >= (ll)(n); i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define pb push_back

template<typename T>
vector<T> unique(vector<T> a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    return a;
}
template<typename T>
void prv(vector<T> a, bool flag = false) {
    if (flag) {
        cout << sz(a) << " ";
    }
    repi (i, 1, sz(a)) {
        cout << a.at(i - 1) << " ";
    }
    cout << endl;
}
template<typename T>
void prv(vector<vector<T>> a, bool flag = false) {
    repi (i, 1, sz(a)) {
        if (flag) {
            cout << sz(a.at(i - 1)) << " ";
        }
        repi (j, 1, sz(a.at(i - 1))) {
            cout << a.at(i - 1).at(j - 1) << " ";
        }
        cout << endl;
    } 
}
template<typename T>
vector<vector<T>> trans(vector<vector<T>> a) {
    vector<vector<T>> a_trans(sz(a.at(0)), vector<T>(sz(a), 0));
    repi(i, 1, sz(a.at(0))) {
        repi(j, 1, sz(a)) {
            a_trans.at(i - 1).at(j - 1) = a.at(j - 1).at(i - 1);
        }
    }
    return a_trans;
}
template<typename T>
void prl(vector<T> a) {
    repi (i, 1, sz(a)) {
        cout << a.at(i - 1) << " ";
    }
}
template<typename T>
void prvp(vector<pair<T, T>> a) {
    repi (i, 1, sz(a)) {
        cout << a.at(i - 1).first << " " << a.at(i - 1).second << endl;
    }
}
template<typename T>
void listin(vector<T>& A, ll n) {
    repi (i, 1, n) {
        T a;
        cin >> a;
        A.pb(a);
    }
}
template<typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<ll> topological_sort(vector<vector<ll>> &graph) {
    ll n = sz(graph);
    vector<ll> in(n, 0);
    repi (i, 0, n - 1) {
        for (ll to : graph.at(i)) {
            in.at(to)++;
        }
    }
    queue<ll> que;
    repi (i, 0, n - 1) {
        if (in.at(i) == 0) {
            que.push(i);
        }
    }
    vector<ll> res;
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        res.push_back(v);
        for (ll to : graph.at(v)) {
            in.at(to)--;
            if (in.at(to) == 0) {
                que.push(to);
            }
        }
    }
    return res;
}

ll n, m, x, y;

int main() {
    cin >> n >> m;
    vvll G(n + 1);
    repi (i, 1, m) {
        cin >> x >> y;
        G.at(x).pb(y);
    }
    vll dp(n + 1, 0);
    for (ll v : topological_sort(G)) {
        for (ll nv : G.at(v)) {
            chmax(dp.at(nv), dp.at(v) + 1);
        }
    }
    cout << *max_element(all(dp)) << endl;
    return 0;
}