 #include <iostream>
 #include <queue>
 using namespace std;
 priority_queue<int> q1,q2;
 int n,m;
 void add(int a) {
     if (a>q2.top()) {
         q1.push(-a);

     } else {
        q2.push(a);
    }
    if (q2.size()+1>q1.size()) {
        q1.push(-q2.top());
        q2.pop();
    }
    if (q1.size()>q2.size()) {
        q2.push(-q1.top());
        q1.pop();

    }


}
 
 int main() {  
   
    cin>>n; 
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        if (i>0) {add(a);}
               else {q2.push(a);}
    }
    cin>>m; 
    for (int i=0;i<m;i++) {
        string cmd;
        int a;
        cin>>cmd;
        if (cmd=="add") {
            cin>>a;add(a);
        }
        else {cout<<q2.top()<<endl;}
    }
}