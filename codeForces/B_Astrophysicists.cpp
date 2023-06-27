#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, g;
        std::cin >> n >> k >> g;

        int saved_silver_coins = 0;

        for (int i = 0; i < n; i++) {
            int bonus;
            std::cin >> bonus;

            int remainder = bonus % g;
            int rounded_bonus;

            if (remainder >= (g + 1) / 2) {
                rounded_bonus = bonus + (g - remainder);
            } else {
                rounded_bonus = bonus - remainder;
            }

            saved_silver_coins += rounded_bonus - bonus;
        }

        std::cout << saved_silver_coins << std::endl;
    }

    return 0;
}
