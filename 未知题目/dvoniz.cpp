#include <iostream>  
using namespace std; int n,s,a[100000],g[100000],q[100000];int main() {cin>>n>>s; for (int i=0;i<n;i++) cin>>a[i];int k=0;int sum=0;  for (int i=0;i<n;i++) { while ((k<n)&&(a[k]+sum<=s)) {	  sum+=a[k];k++;  } g[i]=k; sum-=a[i]; } int t=-1; int h=0; g[n]=n; int j=0;for (int i=0;i<n;i++) {while (j<=g[i]) {	while (h<=t) {		int l=q[t];	if (2*l-g[l]>=2*j-g[j]) t--;else break;	} t++;q[t]=j;j++;		}	if (q[h]<i) h++; while (h<t) {	int l=q[h+1];	if (2*l-g[l]<=i) h++;        else break;}cout<<(q[h]-i)*2<<endl; }}
  







