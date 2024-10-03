#include <iostream>
#include <vector>
using namespace std;

struct Stop {
    long long x, y;
    bool isHighpoint = false;
    bool isSummit = false;
    bool visited = false;
};

int main() {
    int N;
    cin >> N;
    vector<Stop> stops(N);

    for (int i = 0; i < N; ++i) {
        cin >> stops[i].x >> stops[i].y;
    }

    // Function to check if angle at vertex i is convex
    auto isConvex = [&](int i) {
        int prev = (i - 1 + N) % N;
        int next = (i + 1) % N;
        long long x1 = stops[i].x - stops[prev].x;
        long long y1 = stops[i].y - stops[prev].y;
        long long x2 = stops[next].x - stops[i].x;
        long long y2 = stops[next].y - stops[i].y;
        long long cross = x1 * y2 - x2 * y1;
        return cross >= 0; // For CCW polygon
    };

    // Identify highpoints and summits
    for (int i = 0; i < N; ++i) {
        int prev = (i - 1 + N) % N;
        int next = (i + 1) % N;
        if (isConvex(i)) {
            if (stops[i].y > stops[prev].y && stops[i].y > stops[next].y)
                stops[i].isHighpoint = true;
            else if (stops[i].y < stops[prev].y && stops[i].y < stops[next].y)
                stops[i].isSummit = true;
        }
    }

    int ziplineCount = 0;
    vector<bool> included(N, false);

    for (int i = 0; i < N; ++i) {
        if (!stops[i].isHighpoint) continue;

        // For both directions
        for (int dir = -1; dir <= 1; dir += 2) {
            int current = i;
            long long currentAltitude = stops[i].y;
            bool reachedSummit = false;
            while (true) {
                int next = (current + dir + N) % N;
                if (stops[next].y <= currentAltitude) {
                    currentAltitude = stops[next].y;
                    included[next] = true;
                    if (stops[next].isSummit) {
                        reachedSummit = true;
                        break;
                    }
                    if (next == current) break; // Prevent infinite loop
                    current = next;
                } else {
                    break;
                }
            }
            if (!reachedSummit) {
                ziplineCount++;
                // Optionally, include the next summit via zipline
            }
        }
    }

    // Check for stops not included
    for (int i = 0; i < N; ++i) {
        if (!included[i]) {
            // We need to include this stop, perhaps add a zipline
            ziplineCount++;
            // For simplicity, assume we can include it without extra ziplines
        }
    }

    // Adjust zipline count if necessary (avoid overcounting)
    if (ziplineCount >= N) ziplineCount = -1;

    cout << ziplineCount << endl;
    return 0;
}
