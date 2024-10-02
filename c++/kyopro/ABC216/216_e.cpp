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

ll n, k;
vll A;

int main() {
    cin >> n >> k;
    listin(A, n);
    map<ll, ll> m;
    ll sum = 0;
    repi (i, 1, n) {
        m[A.at(i - 1)]++;
        sum += A.at(i - 1);
    }
    vll Acopy = unique(A);
    reverse(all(Acopy));
    if (k >= sum) {
        sum = 0;
        repi (i, 1, n) {
            sum += (A.at(i - 1) * (A.at(i - 1) + 1)) / 2;
        }
        cout << sum << endl;
        return 0;
    }
    sum = 0;
    repi (i, 1, sz(Acopy)) {
        ll dif = 0;
        if (i == sz(Acopy)) {
            dif = Acopy.at(i - 1);
        }
        else {
            dif = Acopy.at(i - 1) - Acopy.at(i);
        }
        ll alpha = Acopy.at(i - 1);
        ll psum = (m[alpha] * dif * (2 * alpha - dif + 1)) / 2;
        if (m[alpha] * dif <= k) {
            k -= m[alpha] * dif;
            sum += psum;
            if (i != sz(Acopy)) {
                m[Acopy.at(i)] += m[alpha];
            }
        }
        else {
            ll div = k / m[alpha], srp = k % m[alpha];
            psum = (m[alpha] * div * (2 * alpha - div + 1)) / 2;
            sum += psum + (alpha - div) * srp;
            break;
        }
    }
    cout << sum << endl;
    return 0;
}