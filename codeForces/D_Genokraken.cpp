#include<bits/stdc++.h>
using namespace std;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int response;
    cin >> response;
    return response;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> parent(n, -1);
        
        vector<int> children;
        for (int i = 1; i < n; ++i) {
            if (query(1, i) == 1) {
                children.push_back(i);
            }
        }

        parent[children[0]] = 0;
        parent[children[1]] = 0;

        for (int i = 2; i < children.size(); ++i) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (query(children[mid], children[i]) == 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            parent[children[i]] = children[l];
        }

        for (int i = 2; i < n; ++i) {
            if (parent[i] == -1) {
                parent[i] = 0;
            }
        }

        cout << "! ";
        for (int i = 1; i < n; ++i) {
            cout << parent[i] << " ";
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}
