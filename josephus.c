// josephus.c  -- Josephus problem (iterative)
#include <stdio.h>

int josephus(int n, int k) {
    int res = 0; // 0-based index
    for (int i = 1; i <= n; ++i) res = (res + k) % i;
    return res + 1; // convert to 1-based
}

int main() {
    int n = 7, k = 3;
    printf("Josephus(%d, %d) = %d\n", n, k, josephus(n,k));
    return 0;
}
