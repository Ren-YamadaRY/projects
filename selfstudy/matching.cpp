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

ll n, m, a, b; // nは人数
string s;

int main() {
    cin >> n >> m >> s;
    if (s == "男性") {
        //男性基準の安定結婚問題
        map<ll, qll> men; // 男性の希望リスト
        qll menlist; // 未婚約男性のリスト
        map<pll, ll> women; // 女性の希望リスト
        repi (i, 1, n) {
            repi (j, 1, m) {
                cin >> a;
                men[i].push(a); // 男性の希望リストを作成
            }
            menlist.push(i); // 未婚約男性のリストに追加
        }
        repi (i, 1, m) {
            repi (j, 1, n) {
                cin >> b;
                women[{b, j}] = j; // 女性の希望リストを作成
            }
        }
        vector<pll> ans(m + 1, {0, 0}); // 結婚相手のリスト（男性、女性）
        while (!menlist.empty()) {
            ll manid = menlist.front(); // 未婚約男性のリストの先頭の男性
            menlist.pop(); // 未婚約男性のリストの先頭の男性を削除
            ll womanid = men[manid].front(); // 男性の希望リストの先頭の女性
            men[manid].pop(); // 男性の希望リストの先頭の女性を削除
            if (ans.at(womanid).second == 0) { // 相手がいないとき
                ans.at(womanid) = {manid, womanid}; // 男性と女性を仮結婚させる
            }
            else if (women[ans.at(womanid)] > women[{manid, womanid}]) { // 既存のペアよりも希望度が高いとき
                menlist.push(ans.at(womanid).first); // 既存のペアの男性を未婚約男性のリストに追加
                ans.at(womanid) = {manid, womanid}; // 男性と女性を仮結婚させる
            }
            else { // 既存のペアよりも希望度が低いとき
                menlist.push(manid); // 男性を未婚約男性のリストに追加
            }
        }
        cout << "男" << " " << "女" << endl;
        sort(all(ans));
        repi (i, 1, m) {
            cout << ans.at(i).first << " " << ans.at(i).second << endl; // 答えを出力（男性、女性）
        }
    }
    if (s == "女性") {
        // 女性基準の安定結婚問題
        map<ll, qll> women; // 女性の希望リスト
        qll womenlist; // 未婚約女性のリスト
        map<pll, ll> men; // 男性の希望リスト
        repi(i, 1, n) {
            repi(j, 1, m) {
                cin >> a;
                men[{a, j}] = j; // 女性の希望リストを作成
            }
        }
        repi(i, 1, m) {
            repi(j, 1, n) {
                cin >> b;
                women[i].push(b); // 男性の希望リストを作成
            }
            womenlist.push(i); // 未婚約女性のリストに追加
        }

        vector<pll> ans(m + 1, {0, 0}); // 結婚相手のリスト（女性、男性）
        while (!womenlist.empty() && !women[womenlist.front()].empty()) {
            ll womanid = womenlist.front(); // 未婚約女性のリストの先頭の女性
            womenlist.pop(); // 未婚約女性のリストの先頭の女性を削除
            ll manid = women[womanid].front(); // 女性の希望リストの先頭の男性
            women[womanid].pop(); // 女性の希望リストの先頭の男性を削除
            cout << manid << " " << womanid << endl;
            if (ans.at(manid).second == 0) { // 男性が誰とも婚約していない場合
                ans.at(manid) = {womanid, manid}; // 女性と男性を仮婚約させる
            } 
            else if (men[ans.at(manid)] > men[{womanid, manid}]) { // 既存のペアよりも希望度が高い場合
                womenlist.push(ans.at(manid).first); // 既存のペアの女性を未婚約女性のリストに追加
                ans.at(manid) = {womanid, manid}; // 女性と男性を仮婚約させる
            } 
            else { // 既存のペアよりも希望度が低い場合
                womenlist.push(womanid); // 女性を未婚約女性のリストに追加
            }
        }

        cout << "女" << " " << "男" << endl;
        sort(all(ans));
        repi(i, 1, m) {
            cout << ans.at(i).first << " " << ans.at(i).second << endl; // 結果を出力（女性、男性）
        }
    }
    else {
        return 0;
    }
    return 0;
}