#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol(){
	int n;
    cin>>n;

    set<int> cero,dos,izq,der;
    for(int i=0; i<n; i++){
        int x;string y;
        cin>>x>>y;

        if(y=="00")         cero.insert(x);
        else if(y=="01")    der.insert(x);
        else if(y=="10")    izq.insert(x);
        else                dos.insert(x);
    }

    int res = INT_MAX;
    if((int)dos.size())    res = min(res,*dos.begin());
    if((int)der.size() && (int)izq.size())  res = min(res,*der.begin()+*izq.begin());


    if(res==INT_MAX)    cout << -1 << "\n";
    else                cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		sol();
	}

	return 0;
}