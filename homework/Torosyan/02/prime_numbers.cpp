#include <iostream>

#include "numbers.dat"

enum { MAX_NUMBER = 100001};

int main(int argc, char *argv[]) {
    bool* is_prime = new bool[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; ++i) {
        is_prime[i] = 1;
    }
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i < MAX_NUMBER; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_NUMBER; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    int left, right, ans;
    if (argc % 2 == 0 || argc == 1) {
        return -1;
    }
    for (int i = 1; i < argc; i += 2) {
        left = atoi(argv[i]);
        right = atoi(argv[i + 1]);
        int j = 0;
        if (left > right) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (j < Size - 1 && Data[j] < left) {
            j++;
        };
        if (Data[j] != left) {
            std::cout << 0 << std::endl;
            continue;
        };
        ans = 0;
        while (j < Size && Data[j] <= right) {
            if (is_prime[Data[j]]) {
                ans++;
            }
            ++j;
        }
        if (Data[j - 1] != right) {
            std::cout << 0 << std::endl;
            continue;
        }
        std::cout << ans << std::endl;
    }
    delete[] is_prime;
    return 0;
}