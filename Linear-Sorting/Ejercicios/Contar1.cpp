#include <iostream>
using namespace std;

using ull = unsigned long long;

ull F(ull n) {
    ull ans = 0;

    for (int k = 0; k < 60; k++) {
        ull half = 1ULL << k;
        ull len = half << 1;

        ull full = (n + 1) / len;
        ull rem = (n + 1) % len;

        ans += full * half;

        if (rem > half)
            ans += rem - half;
    }

    return ans;
}

int main() {
    ull A, B;

    while (cin >> A >> B) {
        if (A == 0)
            cout << F(B) << '\n';
        else
            cout << F(B) - F(A - 1) << '\n';
    }

    return 0;
}