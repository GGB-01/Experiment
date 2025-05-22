#include <iostream>
#include <algorithm>
using namespace std;

// 物品数量
const int N = 4;
// 背包容量
const int CAPACITY = 50;
// 物品重量数组
int weights[N] = {20, 10, 30, 40};
// 物品价值数组
int values[N] = {100, 60, 120, 160};
// 当前最优价值
int bestValue = 0;

// 回溯函数
// idx: 当前考虑的物品索引
// currentWeight: 当前背包重量
// currentValue: 当前背包价值
// remainingValue: 剩余物品的总价值
void backtrack(int idx, int currentWeight, int currentValue, int remainingValue) {
    // 如果已经考虑完所有物品，更新最优解
    if (idx == N) {
        if (currentValue > bestValue) {
            bestValue = currentValue;
        }
        return;
    }

    // 剪枝条件：如果当前价值加上剩余价值仍小于等于最优解，无需继续
    if (currentValue + remainingValue <= bestValue) {
        return;
    }

    // 选择当前物品
    if (currentWeight + weights[idx] <= CAPACITY) {
        backtrack(idx + 1, currentWeight + weights[idx], 
                  currentValue + values[idx], remainingValue - values[idx]);
    }

    // 不选择当前物品
    backtrack(idx + 1, currentWeight, currentValue, remainingValue - values[idx]);
}

int main() {
    // 计算所有物品的总价值
    int totalValue = 0;
    for (int i = 0; i < N; i++) {
        totalValue += values[i];
    }

    // 从第一个物品开始回溯
    backtrack(0, 0, 0, totalValue);

    cout << "背包能装入的最大价值为: " << bestValue << endl;
    return 0;
}