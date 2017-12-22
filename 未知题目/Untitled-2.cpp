#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[100001],ans[100001],m,k,fa[50001][16],maxin;
vector<int> g[50001];

int lca(int u,int v) {
    if (d[u]<d[v]) {
        int temp=u;u=v;v=temp;
    }
    for (int i=15;i>=0;i--) 
        if (d[u]-d[v]>=(1<<i)) u=fa[u][i];
    if  (u==v) return u;
    for (int i=15;i>=0;i--) 
        if (fa[u][i]!=fa[v][i]) {
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}

void dfs(int u,int p) {
    fa[u][0]=p;
    d[u]=d[p]+1;
    for (int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if (v!=p) {
            dfs(v,u);
        }
    }
}

void dfs2(int u,int p) {
    for (int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if (v!=p) {
            dfs2(v,u);
            ans[u]+=ans[v];
        }        
    }
}

int main() {
cin>>m>>k;
for (int i=0;i<m-1;i++) {
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
}
dfs(1,0);
for (int i=1;i<=15;i++) {
    for (int u=1;u<=m;u++) {
        int v=fa[u][i-1];
        fa[u][i]=fa[v][i-1];
    }
}
for (int i=0;i<k;i++) {
      int u,v;
    cin>>u>>v;
    int p=lca(u,v);
    int pp=fa[p][0];
    ans[u]++;
    ans[v]++;
    ans[p]--;
    ans[pp]--;
}
dfs2(1,0);
for (int i=1;i<=m;i++) maxin=max(ans[i],maxin);
cout<<maxin;
}

