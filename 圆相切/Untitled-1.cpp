#include <iostream>
#include <algorithm>
using namespace std;

struct event
{
    long long time;
    int type;
    int id;
};
event e[300000];
long long r[100005],x[100005],stack[100005],a[100005],st,n;
bool cmp(event a,event b) {
    if (a.time==b.time) {
        if (a.type==b.type) {
            if (a.type==1)   
               return (r[a.id]>r[b.id]);
            else 
                return (r[a.id]<r[b.id]);        
        }
        else return (a.type==2);
    }
    else return (a.time<b.time);
} 

int main() {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>x[i]>>r[i];
        e[2*i].id=i;
        e[2*i+1].id=i;
        e[2*i].type=1;
        e[2*i+1].type=2;
        e[2*i].time=x[i]-r[i];
        e[2*i+1].time=x[i]+r[i];
    }
    sort(e,e+n+n,cmp);
    stack[0]=n+1;
    for (int i=0;i<n*2;i++) {
        if (e[i].type==1)  {
            st++;
            stack[st]=e[i].id;
            a[stack[st-1]]+=r[e[i].id];
        }
        if (e[i].type==2) {
            st--;
        }        
    }
    int ans = n+1;
    for (int i=0;i<n;i++) {
        if (a[i]==r[i]) ans++;
    }
    cout<<ans<<endl;
}