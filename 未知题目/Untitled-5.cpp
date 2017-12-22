char find(long long k) {
    if (k=n) return s[k-1];
    int len=n;
    while (2*len<k) len=len*2;
    k==len; 
    if (k==1) return find(len);
            else return find(k-1);
            

}
string s;
int n;
int main() {
    cin>>s>>k;
}