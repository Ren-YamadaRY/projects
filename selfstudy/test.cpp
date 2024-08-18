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

ll n, a, b, c, d, e, f; // nは人数、aからfは人の名前
map<ll, qll> men; // 男性の希望リスト
qll menlist; // 未婚約男性のリスト
map<pll, ll> women; // 女性の希望リスト

int main() {
    cin >> n;
    repi (i, 1, n) {
        cin >> a >> b >> c;
        // 男性の希望リストを作成
        men[i].push(a);
        men[i].push(b);
        men[i].push(c);
        menlist.push(i); // 未婚約男性のリストに追加
    }
    repi (i, 1, n) {
        cin >> d >> e >> f;
        // 女性にとっての男性の順位を特定
        women[{i, d}] = 1;
        women[{i, e}] = 2;
        women[{i, f}] = 3;
    }
    vector<pll> ans(n + 1, {0, 0}); // 結婚相手のリスト（女性、男性）
    while (!menlist.empty()) {
        ll manid = menlist.front(); // 未婚約男性のリストの先頭の男性
        menlist.pop(); // 未婚約男性のリストの先頭の男性を削除
        ll womanid = men[manid].front(); // 男性の希望リストの先頭の女性
        men[manid].pop(); // 男性の希望リストの先頭の女性を削除
        if (ans.at(womanid).first == 0) { // 相手がいないとき
            ans.at(womanid) = {womanid, manid}; // 男性と女性を仮結婚させる
        }
        else if (women[ans.at(womanid)] > women[{womanid, manid}]) { // 既存のペアよりも希望度が高いとき
            menlist.push(ans.at(womanid).second); // 既存のペアの男性を未婚約男性のリストに追加
            ans.at(womanid) = {womanid, manid}; // 男性と女性を仮結婚させる
        }
        else { // 既存のペアよりも希望度が低いとき
            menlist.push(manid); // 男性を未婚約男性のリストに追加
        }
    }
    cout << "男" << " " << "女" << endl;
    repi (i, 1, n) {
        cout << ans.at(i).second << " " << ans.at(i).first << endl; // 答えを出力（男性、女性）
    }
    return 0;
}