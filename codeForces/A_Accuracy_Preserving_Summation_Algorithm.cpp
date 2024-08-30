#include <bits/stdc++.h>
using namespace std;

#define RAND(a, b) uniform_int_distribution<int>(a, b)(rng)
#define RANDR(a, b) uniform_real_distribution<double>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << "\n";
#else
    #define debug(x)
#endif

chrono::high_resolution_clock::time_point start;

//simulated fp16
class Float16{
    static const uint32_t mantissaShift = 42;
    static const uint32_t expShiftMid   = 56;
    static const uint32_t expShiftOut   = 52;
    double dValue_;

public:    
    Float16(double in) : dValue_(in) {
        uint64_t utmp;
        memcpy(&utmp, &dValue_, sizeof utmp);
        //zeroing mantissa bits starting from 11th (this is NOT rounding)
        utmp = utmp >> mantissaShift;
        utmp = utmp << mantissaShift;
        //setting masks for 5-bit exponent extraction out of 11-bit one
        const uint64_t maskExpMid = (63llu << expShiftMid);
        const uint64_t maskExpOut = (15llu << expShiftOut);
        const uint64_t maskExpLead = (1llu << 62);
        const uint64_t maskMantissaD = (1llu << 63) + maskExpLead + maskExpMid + maskExpOut;
        if (utmp & maskExpLead) {// checking leading bit, suspect overflow
            if (utmp & maskExpMid) { //Detected overflow if at least 1 bit is non-zero
                //Assign Inf with proper sign
                utmp = utmp | maskExpMid; //setting 1s in the middle 6 bits of of exponent
                utmp = utmp & maskMantissaD; //zeroing mantissa irrelative of original values to prevent NaN
                utmp = utmp | maskExpOut; //setting 1s in the last 4 bits of exponent
            }
        } else { //checking small numbers according to exponent range
            if ((utmp & maskExpMid) != maskExpMid) { //Detected underflow if at least 1 bit is 0
                utmp = 0;
            }
        }
        memcpy(&dValue_, &utmp, sizeof utmp);
    }

    Float16() : dValue_(0) {}

    Float16& operator=(const Float16& rhs) {
        this->dValue_ = rhs.dValue_;
        return *this;
    }

    Float16& operator=(const double& rhs) {
        this->dValue_ = rhs;
        uint64_t utmp;
        memcpy(&utmp, &dValue_, sizeof utmp);
        utmp = utmp >> mantissaShift;
        utmp = utmp << mantissaShift;
        memcpy(&dValue_, &utmp, sizeof utmp);
        return *this;
    }

    friend Float16 operator+(const Float16& lhs, const Float16& rhs) {
        double tmp = lhs.dValue_ + rhs.dValue_;
        return Float16(tmp);
    }

    float convert2Float() { return static_cast<float>(dValue_); }
    double convert2Double() { return dValue_; }
};

struct node {
    double realSum = 0.0;
    double proposedSum = 0.0;

    int type = 0;

    int cnt16 = 0;
    int cnt32 = 0;
    int cnt64 = 0;

    int state = 0;

    node () {}

    node (double v) {
        realSum = proposedSum = v;
    }

    node (double rS, double pS, int t) {
        realSum = rS;
        pS = proposedSum;
        type = t;
    }
};

ostream& operator<<(ostream& os, const node &n) {
    os << "realSum: " << n.realSum << "\n";
    os << "proposedSum: " << n.proposedSum << "\n";
    os << "cnt16: " << n.cnt16 << "\n";
    os << "cnt32: " << n.cnt32 << "\n";
    os << "cnt64: " << n.cnt64 << "\n";
    os << "type: " << n.type << "\n";
    return os;
}

inline node combine (const node &a, const node &b, const int &type) {
    node result;

    result.realSum = a.realSum + b.realSum;

    result.cnt16 = a.cnt16 + b.cnt16;
    result.cnt32 = a.cnt32 + b.cnt32;
    result.cnt64 = a.cnt64 + b.cnt64;

    result.type = type;

    int lSate = a.state ? 2 : 0;
    int rSate = b.state ? 1 : 0;
    result.state = lSate | rSate;

    double num1 = a.proposedSum;
    double num2 = b.proposedSum;
    Float16 f1(0), f2(0), res(0); 
    switch (type) {
        case 0:
            f1 = Float16(num1);
            f2 = Float16(num2);
            res = f1 + f2;
            result.proposedSum = res.convert2Double();
            result.cnt16++;
            break;
        case 1:
            result.proposedSum = static_cast<float>(num1) + static_cast<float>(num2);
            result.cnt32++;
            break;
        case 2:
            result.proposedSum = num1 + num2;
            result.cnt64++;
            break;
        default:
            cerr << "Unknown type\n";
    }

    return result;
}

inline void completeUpdate (vector<node> &currentSolution) {
    int n = currentSolution.size() >> 1;

    for (int i = n - 1; i > 0; i--) {
        currentSolution[i] = combine(currentSolution[i << 1], currentSolution[i << 1 | 1], currentSolution[i].type);
        assert((i << 1) != (i << 1 | 1));
    }
}

inline void singleUpdate (vector<node> &currentSolution, int idx, const int &type) {
    int n = currentSolution.size() >> 1;

    assert((idx << 1) != (idx << 1 | 1));
    currentSolution[idx] = combine(currentSolution[idx << 1], currentSolution[idx << 1 | 1], type);
    for (; idx >>= 1;) {
        assert((idx << 1) != (idx << 1 | 1));
        currentSolution[idx] = combine(currentSolution[idx << 1], currentSolution[idx << 1 | 1], currentSolution[idx].type);
    }
}

inline string helperType (const int &type) {
    if (type == 0)
        return "h";
    if (type == 1)
        return "s";
    return "d";
}

// Antes de mejora de los nodos
string getAlgorithm(const vector<node> &currentSolution, const int &n, int idx) {
    if (idx >= n) {
        return to_string(idx - n + 1);
    }

    if (currentSolution[idx].state == 3) {
        string left = getAlgorithm(currentSolution, n, idx << 1);
        string right = getAlgorithm(currentSolution, n, idx << 1 | 1);
        
        return "{" + helperType(currentSolution[idx].type) + ":" + left + "," + right + "}";
    }
    
    string left = getAlgorithm(currentSolution, n, idx << 1);

    return "{" + helperType(currentSolution[idx].type) + ":" + left + "}";
    
}


inline double getA (const vector<node> &currentSolution) {
    double Se = currentSolution[1].realSum;
    double Sc = currentSolution[1].proposedSum;
    double eps1 = 1E-200;
    double eps2 = 1E-20;
    double expo = 0.05;

    double absDiff = abs(Sc - Se);
    double denom = max(abs(Se), eps1);
    double ratio = absDiff / denom;

    double maxVal = max(ratio, eps2);
    double A = pow(maxVal, expo);

    return A;
}

inline double getW (const vector<node> &currentSolution) {
    node n = currentSolution[1];

    int cnt16 = n.cnt16;
    int cnt32 = n.cnt32 * 2;
    int cnt64 = n.cnt64 * 4;

    double W = cnt16 + cnt32 + cnt64;

    return W;
}

// You must've updated the currentSolution before
inline double fitness(const vector<node> &currentSolution) {
    int n = currentSolution.size() >> 1;

    double A = getA(currentSolution);

    double W = getW(currentSolution);
    double C = W / (n - 1);
    double D = 10.0 / sqrt(C + 0.5);

    double score = D / A;

    return score;
}

vector<int> randNumbers;
inline int roulette (int id) {
    double h = log2(id);
    
    double pH = 1 / (h + 1);
    double pD = h / (h + 1);
    // double pS = pH + pD;
    double pS = (pH + pD) / 2;

    double s = pH + pD + pS;

    vector<double> p = {pD, pS, pH};
    for (auto &x: p) {
        x /= s;
    }
    for (int i = 1; i < 3; i++) {
        p[i] += p[i - 1];
    }
    
    double r = RANDR(0.0, 1.0);
    for (int i = 0; i < 3; i++) {
        if (r <= p[i]) {
            return i;
        }
    }

    return 2;
}

/*
Update with a single point and random point
*/
// vector<node> genSol(const vector<node>& currentSolution) {
//     int n = currentSolution.size() >> 1;
//     vector<node> sol = currentSolution;
 
//     int idx = RAND(1, n - 1);
//     singleUpdate(sol, idx, roulette(idx));
 
//     return sol;
// }

// Seleccionar un nodo y bajas
// vector<pair<int, int>> genSol(vector<node>& currentSolution) {
//     int n = currentSolution.size() >> 1;
//     vector<pair<int, int>> changes;

//     int idx = RAND(1, n - 1);
//     while (idx < n) {
//         double dontChange = 1;
//         dontChange /= pow((double)log2(idx + 1), 0.5);
        
//         if (RANDR(0.0, 1.0) <= dontChange) {
//             changes.emplace_back(idx, currentSolution[idx].type);
//             singleUpdate(currentSolution, idx, roulette(idx));
//         }

//         double rSide = RANDR(0.0, 1.0);
//         int side = 0;

//         if (rSide <= (double) 50.0) {
//             side = 1;
//         }
        
//         idx = (idx << 1 | side);
//     }
 
//     return changes;
// } 

// Seleccionar un nodo y subir
vector<pair<int, int>> genSol(vector<node>& currentSolution) {
    int n = currentSolution.size() >> 1;
    vector<pair<int, int>> changes;

    int idx = RAND(1, n - 1);
    while (idx >= 1) {
        double dontChange = 1;
        dontChange /= pow((double)log2(idx + 1), 0.5);
        
        if (RANDR(0.0, 1.0) <= dontChange) {
            changes.emplace_back(idx, currentSolution[idx].type);
            singleUpdate(currentSolution, idx, roulette(idx));
        }
        changes.emplace_back(idx, currentSolution[idx].type);
        singleUpdate(currentSolution, idx, roulette(idx));
        
        idx >>= 1;
    }
 
    return changes;
} 

double linearCooling(double initialTemperature, int iteration, double alpha = 0.95) {
    return initialTemperature - alpha * iteration;
}

double exponentialCooling(double initialTemperature, int iteration, double alpha = 0.999) {
    return initialTemperature * pow(alpha, iteration);
}

double adaptiveCooling(double initialTemperature, int iteration, double improvementRate) {
    double alpha = 0.9 + 0.1 * improvementRate; // Ajusta `alpha` en función de la tasa de mejora
    return initialTemperature * pow(alpha, iteration);
}

double coolingLogarithmic(double initialTemperature, int iteration) {
    return initialTemperature / (1 + log(1 + iteration));
}

// Delta postivo, es mas flexible
vector<node> annealing (vector<node> &currentSolution) {
    double initialTemperature = 1000000.0;
    double finalTemperature = 0.001;
    int maxIterations = (int) 5E7;
    int improvementCount = 0;

    double temperature = initialTemperature;
    vector<node> bestSolution = currentSolution;
    double bestFitness = fitness(currentSolution);
    double currentFitness = bestFitness;

    debug(bestFitness);

    for (int i = 0; i < maxIterations && temperature > finalTemperature; i++) {
        // debug(i);

        auto changes = genSol(currentSolution);
        reverse(changes.begin(), changes.end());
        double newFitness = fitness(currentSolution);

        double delta = newFitness - currentFitness;
        double acceptanceProbability = exp(-delta / temperature);
        // debug(acceptanceProbability);

        if (newFitness > bestFitness) {
            bestFitness = newFitness;
            bestSolution = currentSolution;
            // debug(bestFitness);
        } 

        if (delta > 0) {
            currentFitness = newFitness;
            improvementCount++;
            // debug(delta);
        } else if (acceptanceProbability < RANDR(0.0, 1.0)) {
            debug(acceptanceProbability);
            currentFitness = newFitness;
            improvementCount++;
        } else {
            for (const auto &[idx, type]: changes) {
                singleUpdate(currentSolution, idx, type);
            }
        }
        
        // temperature = linearCooling(initialTemperature, i);
        temperature = exponentialCooling(initialTemperature, i);
        // temperature = coolingLogarithmic(initialTemperature, i);

        // double improvementRate = static_cast<double>(improvementCount) / (i + 1);
        // temperature = adaptiveCooling(initialTemperature, i, improvementRate);

        chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = chrono::duration_cast<chrono::duration<double>>(now - start);
        if (elapsed.count() >= 9.7) {
            break;
        }
    }

    debug(bestFitness);
    return bestSolution;
}

// Intento extra
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    int nn = 1;
    while (nn < n) {
        nn *= 2;
    }

    vector<double> nums(nn);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);

    vector<node> st(nn << 1);
    for (auto &x: st) {
        x.type = 2;
    }

    for (int i = 0; i < n; i++) {
        st[i + nn] = node(nums[i]);
        st[i + nn].state = 3;
    }

    completeUpdate(st);
    auto sol = annealing(st);
    cout << getAlgorithm(sol, nn, 1) << "\n";

    return 0;
}