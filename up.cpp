#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
vector<int> adj[maxn];
bool mark[maxn];
vector<int> ch[maxn];
int sum[maxn];
int p[maxn];
vector<int> ans;

void dfs_init(int u) {
	mark[u] = 1;
	sum[u] = p[u];
	for(int v: adj[u]) if(!mark[v]) {
		ch[u].pb(v);
		dfs_init(v);
		sum[u] += sum[v];
	}
}

void dfs(int u, int par = -1) {
	if(sum[u] == 0) return;
	ans.pb(u), p[u] ^= 1;
	for(int v: ch[u]) {
		dfs(v, u);
		if(sum[v]) ans.pb(u), p[u] ^= 1;
	}
	if(p[u]) {
		if(par != -1) ans.pb(par), p[par] ^= 1, ans.pb(u), p[u] ^= 1;
		else ans.pb(ch[u].front()), ans.pb(u), p[u] ^= 1, ans.pb(ch[u].front());
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i, n) cin >> p[i];

	dfs_init(0);
	dfs(0);

	cout << sz(ans) << endl;
	rep(i, sz(ans)) cout << ans[i] + 1 << ' ';
	cout << endl;

	{ return 0; }
}
