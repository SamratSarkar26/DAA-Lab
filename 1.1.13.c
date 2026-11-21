#include <stdio.h>
#include <limits.h>

#define MAX 15
#define INF LLONG_MAX / 4

long long dp[1 << MAX][MAX];
int cost[MAX][MAX];
int n;

long long tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        if (cost[pos][0] == -1)
            return INF;
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    long long ans = INF;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city)) && cost[pos][city] != -1) {
            long long next = tsp(mask | (1 << city), city);

            if (next != INF) {
                long long total = cost[pos][city] + next;
                if (total < ans)
                    ans = total;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main(void) {
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            dp[mask][j] = -1;
        }
    }

    long long result = tsp(1, 0);

    if (result == INF)
        printf("-1\n");
    else
        printf("%lld\n", result);

    return 0;
}

