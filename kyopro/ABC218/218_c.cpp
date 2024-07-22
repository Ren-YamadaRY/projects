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

ll n;
vector<pll> dif;

bool solve (vvc T) {
    bool flag = true;
    ll cnt = 0;
    repi (i, 1, n) {
        repi (j, 1, n) {
            if (T.at(i - 1).at(j - 1) == '#' && cnt == 0) {
                cnt++;
                for (auto p : dif) {
                    ll x = i - 1 + p.first, y = j - 1 + p.second;
                    if (0 > x || x > n - 1 || 0 > y || y > n - 1 || T.at(x).at(y) != '#') {
                        flag = false;
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
            if (!flag || cnt != 0) {
                break;
            }
        }
        if (!flag || cnt != 0) {
            break;
        }
    }
    return flag;
}

int main() {
    cin >> n;
    vvc S(n, vc(n, '_'));
    vvc T(n, vc(n, '_')), T_1(n, vc(n, '_')), T_2(n, vc(n, '_')), T_3(n, vc(n, '_'));
    ll cnt = 0, x = 0, y = 0;
    repi (i, 1, n) {
        repi (j, 1, n) {
            cin >> S.at(i - 1).at(j - 1);
            if (S.at(i - 1).at(j - 1) == '#' && cnt == 0) {
                cnt++;
                x = i - 1, y = j - 1;
            }
            else if (S.at(i - 1).at(j - 1) == '#') {
                cnt++;
                dif.pb(make_pair(i - 1 - x, j - 1 - y));
            }
        }
    }
    repi (i, 1, n) {
        repi (j, 1, n) {
            cin >> T.at(i - 1).at(j - 1);
            if (T.at(i - 1).at(j - 1) == '#') {
                cnt--;
            }
        }
    }
    if (cnt != 0) {
        cout << "No" << endl;
        return 0;
    }
    repi (i, 1, n) {
        repi (j, 1, n) {
            T_1.at(i - 1).at(j - 1) = T.at(n - j).at(i - 1);
        }
    }
    repi (i, 1, n) {
        repi (j, 1, n) {
            T_2.at(i - 1).at(j - 1) = T_1.at(n - j).at(i - 1);
        }
    }
    repi (i, 1, n) {
        repi (j, 1, n) {
            T_3.at(i - 1).at(j - 1) = T_2.at(n - j).at(i - 1);
        }
    }
    bool ans = solve(T), ans_1 = solve(T_1), ans_2 = solve(T_2), ans_3 = solve(T_3);
    if (ans + ans_1 + ans_2 + ans_3 > 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}