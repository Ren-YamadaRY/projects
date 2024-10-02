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

ll n, m, k, a;
vector<sll> s(200009);

int main() {
    cin >> n >> m;
    repi (i, 1, m) {
        cin >> k;
        repi (j, 1, k) {
            cin >> a;
            s.at(i - 1).push(a);
        }
    }
    queue<pll> q;
    map<ll, ll> mp;
    repi (i, 1, m) {
        if (!s.at(i - 1).empty()) {
            if (!mp.count(s.at(i - 1).top())) {
                mp[s.at(i - 1).top()] = i - 1;
            }
            else {
                q.push(make_pair(i - 1, mp[s.at(i - 1).top()]));
            }
        }
    }
    vll ans;
    while (!q.empty()) {
        pll p = q.front();
        ll fst = p.first, snd = p.second;
        q.pop();
        ans.pb(s.at(fst).top());
        s.at(fst).pop();
        s.at(snd).pop();
        if (!s.at(fst).empty()) {
            if (!mp.count(s.at(fst).top())) {
                mp[s.at(fst).top()] = fst;
            }
            else {
                q.push(make_pair(fst, mp[s.at(fst).top()]));
            }
        }
        if (!s.at(snd).empty()) {
            if (!mp.count(s.at(snd).top())) {
                mp[s.at(snd).top()] = snd;
            }
            else {
                q.push(make_pair(snd, mp[s.at(snd).top()]));
            }
        }
    }
    if (sz(ans) == n) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}