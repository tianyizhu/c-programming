#include <iostream>
#include <vector>
using namespace std;
vector <int> member[200];
vector <int> solu;

struct pp{
    int fi,se,fs,ss;
};

pp group[200];
bool f[200][200],w[200][200],g[200][200];
int p[200],opp[200];
int id,i,n,u,v,k,s,fs,ans;

int find(int u) {
    if (p[u]==0) return u;
    p[u]=find(p[u]);
    return p[u];
}

int merge(int u,int v){
    if (v==0) return u;
    u=find(u);
    v=find(v);
    if (u!=v) {
        p[u]=v;
    }
    return v; 
}

int gen(int i,int x) {
   
    if (i==0) return 0;
    if (w[i][x]) id=group[i].fi;
            else id=group[i].se;

    solu.insert(solu.end(),
                   member[id].begin(),
                   member[id].end());
    if (w[i][x]) gen(i-1,x-group[i].fs);
            else gen(i-1,x-group[i].ss);
    
}
int main() {
    cin>>n;
    for (int u=1;u<=n;u++) {
        cin>>v;
        while (v>0) {
            g[u][v]=true;
            cin>>v;
        }
    }
    for (int u=1;u<=n;u++) {
        for (int v=u+1;v<=n;u++) {
            if ((g[u][v]==false)||(g[v][u]==false)) {
                opp[v]=merge(u,opp[v]);
                opp[u]=merge(v,opp[u]);
            }
        }
    }
    for (int u=1;u<=n;u++) {
        if (find(u)==opp[u]) {
            cout<<-1; 
            return 0;
        }
        id=find(u);
        member[id].push_back(u);
    }

    for (int u=1;u<=n;u++) {
        if (p[u]==0) {
            if ((opp[u]==0)||(opp[u]>u)) {
                k++;
                group[k].fi=u;
                group[k].fs=member[u].size();
                group[k].se=opp[u];
                group[k].ss=member[opp[u]].size();

            }
        }
    }
    f[0][0]=true;
    for (int i=1;i<=k;i++) {
        s=group[i].fs;
        for (int x=fs;x<=n;x++) 
            if (f[i=1][x-s]) {
                f[i][x]=true;
                w[i][x]=true;
            }
        s=group[i].ss;
        for (int x=s;x<=n;x++)
            if (f[i-1][x-s]) {
                f[i][x]=true;
                w[i][x]=false;
           }

    }
    ans=n/2;
    while (!f[k][ans]) ans--;
    gen(k,ans);
    cout<<solu.size()<<' ';
    for (int i=0;i<solu.size();i++) cout<<solu[i]<<' ';
    cout<<endl;
}


    