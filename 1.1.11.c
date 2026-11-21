#include <stdio.h>

int main() {
    int N, W;

    scanf("%d", &N);

    int value[N], weight[N];
    
    for (int i = 0; i < N; i++)
        scanf("%d", &value[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &weight[i]);

    scanf("%d", &W);

    int dp[W + 1];

    for (int i = 0; i <= W; i++)
        dp[i] = 0;

    for (int i = 0; i < N; i++) {

        for (int j = W; j >= weight[i]; j--) {
            int newValue = dp[j - weight[i]] + value[i];

            if (newValue > dp[j])
                dp[j] = newValue;
        }
    }

    printf("%d\n", dp[W]);

    return 0;
}

