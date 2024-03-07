#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool esNumero(string s) {
    for (auto d: s) {
        if (!isdigit(d))
            return false;
    }

    return true;
}

vector<string> separa(string s) {
    vector<string> res;
    string curr = "";
    for (int i = 0; i < s.size(); i++) {
        curr = "";
        while (isdigit(s[i]) && i < s.size()) {
            curr += s[i];
            i++;
        }
        res.push_back(curr);
    }

    reverse(res.begin(), res.end());

    // for (auto x: res) {
    //     cerr << x << " ";
    // }
    // cerr << "\n";

    return res;
}

ll obtenValor(vector<string> t) {
    ll res = 0;

    if (t.size() == 4) {
        res += stoll(t[0]);
        res += stoll(t[1]) * 1000;
        res += stoll(t[2]) * 60 * 1000;
        res += stoll(t[3]) * 60 * 60 * 1000;
    }
    else {
        res += stoll(t[0]);
        res += stoll(t[1]) * 1000;   
    }


    return res;
}

string res (ll tiempo, ll retraso) {
    ll ms = tiempo + retraso;
    int hr = ms / (1000 * 60 * 60);
    ms %= (1000 * 60 * 60);
    int mins = ms / (1000 * 60);
    ms %= (1000 * 60);
    int seconds = ms / 1000;
    ms %= 1000; // Los milisegundos restantes.

    ostringstream oss;
    oss << setw(2) << setfill('0') << hr << ":"
        << setw(2) << setfill('0') << mins << ":"
        << setw(2) << setfill('0') << seconds << ","
        << setw(3) << setfill('0') << ms;

    return oss.str();
}

string res(string t, ll ret) {
    auto ss = separa(t);
    auto ms = obtenValor(ss);
    return res(ms, ret);
}

int main() {
    int n, sub;
    string d;
    cin >> n >> d;

    vector<string> aux = separa(d);
    ll ret = obtenValor(aux);
    // cerr << ret << "\n";

    string s;
    int linea;
    while (getline(cin, s)) {
        if (s != "") {
            if (esNumero(s)) {
                int linea = stoi(s);
                cout << linea << "\n";

                getline(cin, s);
                string t1, sep, t2;
                istringstream iss(s);
                iss >> t1 >> sep >> t2;

                // cout << t1 << " " << sep << " " << t2 << "\n";
                cout << res(t1, ret) << " " << sep << " " << res(t2, ret) << "\n";

                while (getline(cin, s)) {
                    cout << s << "\n";
                    if (s == "") {
                        break;
                    }
                }
            }
        }
    }

    // cout << s << "\n";

    return 0;
}