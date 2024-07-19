#include <bits/stdc++.h>
using namespace std;

typedef __int128_t lli;
typedef long long int ll;
typedef complex<long double> comp;

struct fraccion{
	ll num, den;
	fraccion(){
		num = 0, den = 1;
	}
	fraccion(ll x, ll y){
		if(y < 0)
			x *= -1, y *=-1;
		ll d = __gcd(abs(x), abs(y));
		num = x/d, den = y/d;
	}
	fraccion(ll v){
		num = v;
		den = 1;
	}
	fraccion operator+(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return fraccion(num*(f.den/d) + f.num*(den/d), den*(f.den/d));
	}
	fraccion operator-() const{
		return fraccion(-num, den);
	}
	fraccion operator-(const fraccion& f) const{
		return *this + (-f);
	}
	fraccion operator*(const fraccion& f) const{
		return fraccion(num*f.num, den*f.den);
	}
	fraccion operator/(const fraccion& f) const{
		return fraccion(num*f.den, den*f.num);
	}
	fraccion operator+=(const fraccion& f){
		*this = *this + f;
		return *this;
	}
	fraccion operator-=(const fraccion& f){
		*this = *this - f;
		return *this;
	}
	fraccion operator++(int xd){
		*this = *this + 1;
		return *this;
	}
	fraccion operator--(int xd){
		*this = *this - 1;
		return *this;
	}
	fraccion operator*=(const fraccion& f){
		*this = *this * f;
		return *this;
	}
	fraccion operator/=(const fraccion& f){
		*this = *this / f;
		return *this;
	}
	bool operator==(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return (num*(f.den/d) == (den/d)*f.num);
	}
	bool operator!=(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return (num*(f.den/d) != (den/d)*f.num);
	}
	bool operator >(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return (num*(f.den/d) > (den/d)*f.num);
	}
	bool operator <(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return (num*(f.den/d) < (den/d)*f.num);
	}
	bool operator >=(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return (num*(f.den/d) >= (den/d)*f.num);
	}
	bool operator <=(const fraccion& f) const{
		ll d = __gcd(den, f.den);
		return (num*(f.den/d) <= (den/d)*f.num);
	}
	fraccion inverso() const{
		return fraccion(den, num);
	}
	fraccion fabs() const{
		fraccion nueva;
		nueva.num = abs(num);
		nueva.den = den;
		return nueva;
	}
	double value() const{
		return (double)num / (double)den;
	}
	string str() const{
		stringstream ss;
		ss << num;
		ss << "/" << den;
		return ss.str();
	}
};

ostream &operator<<(ostream &os, const fraccion & f) { 
	return os << f.str();
}

istream &operator>>(istream &is, fraccion & f){
	ll num = 0, den = 1;
	string str;
	is >> str;
	size_t pos = str.find("/");
	if(pos == string::npos){
		istringstream(str) >> num;
	}else{
		istringstream(str.substr(0, pos)) >> num;
		istringstream(str.substr(pos + 1)) >> den;
	}
	f = fraccion(num, den);
	return is;
}

bool igual(long double a, long double b){
    return abs(a - b) < 1e-9;
}

struct polinomio{
    vector<fraccion> coeficientes;
    polinomio(){
        coeficientes.push_back(0);
    }
    polinomio(vector<fraccion> coef){
        for(fraccion x : coef) coeficientes.push_back(x);
        quitar_ceros();
    }
    polinomio(ll x0){
        coeficientes.push_back(x0);
    }
    polinomio(fraccion x0){
        coeficientes.push_back(x0);
    }
    size_t grado() const{
        return coeficientes.size() - 1;
    }
    void quitar_ceros(){
        while(coeficientes.size() && coeficientes.back() == 0){
            coeficientes.pop_back();
        }
        if(coeficientes.size() == 0) coeficientes.push_back(0);
    }
    polinomio operator+(const polinomio& p) const{
        size_t g = max(grado(), p.grado());
        vector<fraccion> nuevos(g + 1, 0);
        for(size_t i = 0; i <= g; i++){
            if(i <= coeficientes.size() - 1) nuevos[i] += coeficientes[i];
            if(i <= p.coeficientes.size() - 1) nuevos[i] += p.coeficientes[i];
        }
        return polinomio(nuevos);
    }
    polinomio operator-() const{
        size_t g = grado();
        vector<fraccion> nuevos(g + 1);
        for(size_t i = 0; i <= g; i++) nuevos[i] = -coeficientes[i];
        return polinomio(nuevos);
    }
    polinomio operator-(const polinomio& p) const{
        return *this + (-p);
    }
    polinomio operator*(const polinomio& p) const{
        size_t g = grado() + p.grado();
        vector<fraccion> nuevos(g + 1, 0);
        for(size_t i = 0; i <= grado(); i++){
            for(size_t j = 0; j <= p.grado(); j++){
                nuevos[i + j] += coeficientes[i] * p.coeficientes[j];
            }
        }
        return polinomio(nuevos);
    }
    polinomio operator*(const fraccion& f) const{
        size_t g = grado();
        vector<fraccion> nuevos(g + 1);
        for(size_t i = 0; i <= g; i++) nuevos[i] = f * coeficientes[i];
        return polinomio(nuevos);
    }
    pair<polinomio, polinomio> operator/(const polinomio& B) const{
        polinomio Q, R;
        Q = 0;
        R = polinomio(coeficientes);
        while(R.grado() >= B.grado() && !(R.grado() == 0 && R.coeficientes[0] == 0)){
            fraccion q = R.coeficientes[R.grado()] / B.coeficientes[B.grado()];
            size_t g = R.grado() - B.grado();
            vector<fraccion> tmp(g + 1, 0);
            tmp[g] = q;
            polinomio nuevo(tmp);
            Q += nuevo;
            R -= B*nuevo;
        }
        return make_pair(Q, R);
    }
    polinomio operator+=(const polinomio& p){
        *this = *this + p;
        return *this;
    }
    polinomio operator-=(const polinomio& p){
        *this = *this - p;
        return *this;
    }
    polinomio operator*=(const polinomio& p){
        *this = *this * p;
        return *this;
    }
    polinomio operator*=(const fraccion& f){
        *this = *this * f;
        return *this;
    }
    fraccion evaluar(fraccion x0){
        fraccion ans = 0;
        for(auto it = coeficientes.rbegin(); it != coeficientes.rend(); ++it){
            ans = ans * x0 + (*it);
        }
        return ans;
    }
    string str(){
        bool primero = true;
        stringstream exp;
        for(int pot = coeficientes.size() - 1; pot >= 0; pot--){
            fraccion coef = coeficientes[pot];
            if(coef > 0){
                if(primero){
                    primero = false;
                }else{
                    exp << " + ";
                }
            }else if(coef < 0){
                if(primero){
                    exp << "-";
                    primero = false;
                }else{
                    exp << " - ";
                }
            }
            if(coef != 1 && coef != -1 && coef != 0){
                if(coef > 0) exp << coef.str();
                else exp << (-coef).str();
            }else{
                if(pot == 0){
                    if(coef > 0) exp << coef.str();
                    else if(coef < 0) exp << (-coef).str();
                }
            }
            if(coef != 0){
                if(pot == 1){
                    exp << "x";
                }
                else if(pot > 1){
                    exp << "x^" << pot;
                }
            }
        }
        string linea = exp.str();
        if(linea.size() == 0) return "0";
        else return linea;
    }
};

polinomio generar_ecuacion(vector<fraccion> raices){
    polinomio ans = 1;
    for(fraccion & raiz : raices) ans *= polinomio(vector<fraccion>{-raiz, 1});
    return ans;
}

void sol () {
    fraccion a, b, c, l, r;
    cin >> a >> b >> c >> l >> r;


}

int main(){
    int tt;
    cin >> tt;

    while (tt--) {
        sol ();
    }

    return 0;
}


/*

0.7381730266596969
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

0.7258886565603764
[1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0]

0.7294171458442237
[1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0]

0.731116048092002
[1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0]

0.7311813904861474
[0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0]

0.7332723470987977
[0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1]





0.7361474124411919
[0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1]

0.7405253528489284
[0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1]

*/