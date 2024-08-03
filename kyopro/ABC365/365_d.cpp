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

ll n;
string s;
bool win(char a, char b) {
    if (a == 'S' && b == 'P') return true;
    if (a == 'P' && b == 'R') return true;
    if (a == 'R' && b == 'S') return true;
    return false;
}
bool lose(char a, char b) {
    if (a == 'P' && b == 'S') return true;
    if (a == 'R' && b == 'P') return true;
    if (a == 'S' && b == 'R') return true;
    return false;
}
vc S = {'P', 'R', 'S'};

int main() {
    cin >> n >> s;
    vvll dp(n + 1, vll(4, 0));
    repi (i, 1, 3) {
        if (win(S.at(i - 1), s.at(0))) {
            dp.at(1).at(i) = 1;
        }
        else if (lose(S.at(i - 1), s.at(0))) {
            dp.at(1).at(i) = -1;
        }
        else {
            dp.at(1).at(i) = 0;
        }
    }
    repi (i, 2, n) {
        repi (j, 1, 3) {
            if (win(S.at(j - 1), s.at(i - 1))) {
                repi (k, 1, 3) {
                    if (j != k && dp.at(i - 1).at(k) != -1) {
                        chmax(dp.at(i).at(j), dp.at(i - 1).at(k) + 1);
                    }
                }
            }
            else if (lose(S.at(j - 1), s.at(i - 1))) {
                dp.at(i).at(j) = -1;
            }
            else {
                repi (k, 1, 3) {
                    if (j != k) {
                        chmax(dp.at(i).at(j), dp.at(i - 1).at(k));
                    }
                }
            }
        }
    }
    ll ans = 0;
    repi (i, 1, 3) {
        ans = max(ans, dp.at(n).at(i));
    }
    cout << ans << endl;
    return 0;
}