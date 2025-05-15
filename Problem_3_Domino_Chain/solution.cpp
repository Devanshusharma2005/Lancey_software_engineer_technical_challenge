#include <iostream>
using namespace std;

#define F ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 7;
const int M = 2000;

struct E { int v, i; };

E g[N][M];
int gc[N];

int d[N], p[N], x[M], y[M];
bool u[M];

int a[M], b[M], sz = 0;

void dfs(int v) {
    while (p[v] < gc[v]) {
        int to = g[v][p[v]].v;
        int i = g[v][p[v]].i;
        ++p[v];
        if (u[i]) continue;
        u[i] = 1;
        dfs(to);
        a[sz] = v;
        b[sz] = to;
        ++sz;
    }
}

int main() {
    F
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v; cin >> u >> v;
        x[i] = u; y[i] = v;
        g[u][gc[u]] = {v, i}; ++gc[u];
        g[v][gc[v]] = {u, i}; ++gc[v];
        ++d[u]; ++d[v];
      }

    int s = -1, o = 0;
    for (int i = 0; i < N; ++i) {
        if (d[i] % 2) ++o, s = i;
        if (d[i]) s = i;
    }

    if (o != 0 && o != 2) {
        cout << "NO\n";
        return 0;
    }

    dfs(s);

    if (sz != n) {
        cout << "NO\n";
        return 0;
    }

    if (a[0]!= b[sz - 1]) {
        cout << "NO\n";
        return 0;
       }

    bool vis[M] = {};
    for (int i = sz -1; i >= 0; --i) {
        int u = a[i], v = b[i];
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                if ((x[j]== u && y[j] == v) || (x[j] == v && y[j] == u)) {
                    cout << x[j] << " " << y[j] << '\n';
                    vis[j] = 1;
                    break;
                }
            }
          }
    }
}
