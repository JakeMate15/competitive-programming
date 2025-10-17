#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 1) extended‐gcd to get inverse
i64 modinv(i64 a, i64 m, i64 s0 = 1, i64 s1 = 0) {
    return m==0 ? s0
                : modinv(m, a % m, s1, s0 - s1*(a/m));
}

// 2) safe multiply mod
i64 mulmod(i64 a, i64 b, i64 m) {
    long double q = (long double)a * b / m;
    i64 r = a*b - (i64)q*m;
    r %= m; if(r<0) r += m;
    return r;
}

// 3) plain gcd
i64 gcd(i64 a, i64 b) {
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        i64 n, x, y, vx, vy;
        cin >> n >> x >> y >> vx >> vy;

        // normalize velocity by its own gcd
        {
            i64 g = gcd(vx, vy);
            vx /= g; vy /= g;
        }

        // compute step‐sizes
        i64 gx = modinv(vx, n) % n; if(gx<0) gx += n;
        i64 gy = modinv(vy, n) % n; if(gy<0) gy += n;
        i64 sx = mulmod(gx, vx, n);
        i64 sy = mulmod(gy, vy, n);
        if(sx==0) sx = n;
        if(sy==0) sy = n;

        // check solvability
        if(x % sx != 0 || y % sy != 0){
            cout << -1 << "\n";
            continue;
        }

        // build moduli and remainders
        i64 px = n / sx;
        i64 py = n / sy;
        i64 rx = ( gx * ((n - x)/sx) ) % px;
        i64 ry = ( gy * ((n - y)/sy) ) % py;
        if(rx<0) rx += px;
        if(ry<0) ry += py;

        // CRT merge: t ≡ rx (mod px), t ≡ ry (mod py)
        i64 g = gcd(px, py);
        if((ry - rx) % g != 0){
            cout << -1 << "\n";
            continue;
        }
        // lcm = px/g * py
        i64 m1g = px / g, m2g = py / g;
        i64 inv = modinv(m1g, m2g) % m2g; if(inv<0) inv += m2g;
        // solve k*(px) ≡ (ry - rx) (mod py) ⇒ k ≡ (ry-rx)/g * inv (mod m2g)
        i64 diff = (ry - rx) / g;
        diff %= m2g; if(diff<0) diff += m2g;
        i64 k = mulmod(diff, inv, m2g);
        // minimal t
        i64 mod_lcm = m1g * py; // = lcm(px,py)
        long long t = ( (__int128)rx + (__int128)px * k ) % mod_lcm;
        if(t<0) t += mod_lcm;

        // compute final unfolded coordinates
        i64 g2 = gcd(vx, vy);
        i64 wx = vx * n / g2;
        i64 wy = vy * n / g2;
        // add vx*t mod wx
        i64 fx = x + mulmod(vx, t, wx);
        i64 fy = y + mulmod(vy, t, wy);

        // count reflections
        i64 A = fx / n;
        i64 B = fy / n;
        i64 cnt = max(0LL, A-1)
               + max(0LL, B-1)
               + (A + B)/2
               +  llabs(A - B)/2;

        cout << cnt << "\n";
    }
    return 0;
}
