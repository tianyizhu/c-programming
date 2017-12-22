#include <iostream>
#include<algorithm>
int n,m,son[3005],bro[3005],w[3005],f[3005][3005],bs,ss;
int dfs(u) {
    int s=son[u];
    int b=bro[u];
    if (s!=0) ss=dfs(s);
            else ss=0;
    if (b!=0) bs=dfs(b);
            else bs=0;
    for (int k=0;k<=n;k++) f[u][k]=f[b][k];
    for (int i=0;i<=ss;i++) 
        for (int j=0;k<=bs;j++) {
            int k=i+j;
            f[u][k]=max(f[u][k],[b][j]+f[s][i]+w[u]);
        }
    return ss+bs;
}
int main() {

    cin>>n>>m;
    for (int i=0;i<=n-m;i++) {
        cin>>k;
        while (k-->0) {
            cin>>u>>c;
            w[u]=-c;
            bro[u]=son[i];
            son[i]=u;
        }
    }
    for (int i=n-m+1;i<=n;i++) {
        cin>>e;
        w[i]+=c;

    }
    for (int i=1;i<=n;i++)
        f[0][i]=1000000;

    dfs(1);
    for (int i=m;i>=0;i--) {
        if f[1][i]>=0 return i;
    }
}