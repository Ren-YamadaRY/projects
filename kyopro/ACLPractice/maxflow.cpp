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
void prv(vector<T> a) {
    repi (i, 1, sz(a)) {
        cout << a.at(i - 1) << " ";
    }
    cout << endl;
}
template<typename T>
void prv(vector<vector<T>> a) {
    repi (i, 1, sz(a)) {
        repi (j, 1, sz(a.at(0))) {
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

ll n, m;
vvc S(109, vc(109, ' '));
vll dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

ll index(ll x, ll y) {
    return x * m + y;
}

int main() {
    cin >> n >> m;
    repi (i, 1, n) {
        repi (j, 1, m) {
            cin >> S.at(i - 1).at(j - 1);
        }
    }
    mf_graph<ll> G(n * m + 2);
    ll s = n * m, t = n * m + 1;
    repi (i, 1, n) {
        repi (j, 1, m) {
            if ((i + j) % 2 == 0) {
                repi (k, 1, 4) {
                    ll nx = i - 1 + dx.at(k - 1), ny = j - 1 + dy.at(k - 1);
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if (S.at(i - 1).at(j - 1) == '.' && S.at(nx).at(ny) == '.') {
                        G.add_edge(index(i - 1, j - 1), index(nx, ny), 1);
                    }
                }
            }
            if ((i + j) % 2 == 0 && S.at(i - 1).at(j - 1) == '.') {
                G.add_edge(s, index(i - 1, j - 1), 1);
            }
            if ((i + j) % 2 == 1 && S.at(i - 1).at(j - 1) == '.') {
                G.add_edge(index(i - 1, j - 1), t, 1);
            }
        }
    }
    ll maxflow = G.flow(s, t);
    const auto& edges = G.edges();
    for (const auto& e : edges) {
        if (e.from == s || e.to == t || e.flow == 0) {
            continue;
        }
        ll from = min(e.from, e.to), to = max(e.from, e.to);
        ll ifrom = from / m, jfrom = from % m;
        ll ito = to / m, jto = to % m;
        if (ifrom == ito) {
            S.at(ifrom).at(jfrom) = '>';
            S.at(ito).at(jto) = '<';
        }
        else {
            S.at(ifrom).at(jfrom) = 'v';
            S.at(ito).at(jto) = '^';
        }
    }
    cout << maxflow << endl;
    repi (i, 1, n) {
        repi (j, 1, m) {
            cout << S.at(i - 1).at(j - 1);
        }
        cout << endl;
    }
    return 0;
}