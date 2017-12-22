struct op{
    int l,r;
    int k;
    bool isQ;
    int qid;
};
solve(int lb;int ub,vector<op> &q)(int t) {
    vector<op> left;
    vector<op> after;
    if (ub-lb==1) {
        for (int i=0;i<q.size;i++) {
            if (q[i].isQ) {
                ans[q[i].qid]=lb;
            }
        }
        return;
    }
    for (int i=0;i<q.size();i++) 
        if (q[i].isQ) {
            int cout=sum(q[i].r)-sum(a[i].l);
            if (a[i].k>=cout) left.pushback(q[i]);
                            else right.push_back(q[i]);

        };
        else {
            if(a[i].k<t) 
        };
    solve(lb,t,left);
    solve(t,lb,right);
}
int main() {
    vector<op> q(n);
    cin>>n;
    for (r=0;i<n;i++) {
        
        cin>>ty>>q[i].l>>g[i].r>>q[i].k;
        q[i].isQ=(ty==2);
        if (ty==2) {
            qid++;q[i].qid=qid;
        }
        solve[-50000,50000,q];
    }
}