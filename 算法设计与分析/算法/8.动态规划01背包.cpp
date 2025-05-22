#include <iostream>
using namespace std;

// 物品数量
const int N = 4;
// 背包容量
const int CAPACITY = 50;
// 物品重量数组
int weights[N] = {20, 10, 30, 40};
// 物品价值数组
int values[N] = {100, 60, 120, 160};
// 动态规划表，dp[i][j]表示前i个物品放入容量为j的背包的最大价值
int dp[N + 1][CAPACITY + 1];

int main() {
    // 初始化dp数组
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= CAPACITY; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // 没有物品或容量为0时价值为0
            } else if (weights[i - 1] <= j) {
                // 选择放入或不放入当前物品，取最大值
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]],
                               dp[i - 1][j]);
            } else {
                // 当前物品重量超过容量，不能放入
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 输出最大价值
    cout << "背包能装入的最大价值为: " << dp[N][CAPACITY] << endl;

    // 回溯找出选择的物品
    int j = CAPACITY;
    cout << "选择的物品编号为: ";
    for (int i = N; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << i << " ";
            j -= weights[i - 1];
        }
    }
    cout << endl;

    return 0;
}