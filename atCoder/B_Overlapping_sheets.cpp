#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

long long area(int bl_x, int bl_y, int tr_x, int tr_y) {
	long long length = tr_y - bl_y;
	long long width = tr_x - bl_x;
	return length * width;
}

int inter_area(vector<int> s1, vector<int> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	return ((min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) *
	        (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)));
}

void sol(){
    int n;
    cin>>n;

    ll ar = 0;
    vector<vector<int>> rectangulos(n, vector<int>(2));
    forn(i,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        rectangulos[i][0] = a;
        rectangulos[i][1] = c;
        rectangulos[i][2] = b;
        rectangulos[i][3] = d;

        ar+=area(a,c,b,d);
    }

    forn(i,n){
        forn(j,n){
            if(j==i)    continue;
            debln(inter_area(rectangulos[i],rectangulos[j]));
            ar-=inter_area(rectangulos[i],rectangulos[j]);
        }
    }

    debln(ar);

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}