// 计算单位价值：计算每个物品的单位价值（价值 / 重量）。
// 物品排序：按照单位价值从高到低对物品进行排序。
// 选择物品：按排序顺序依次检查物品，只要背包剩余容量能容纳当前物品，就将其放入背包，直到背包容量被占满或物品全部检查完。

#include <iostream>
#include <algorithm>
using namespace std;

// 物品数量
const int N = 7;
// 背包容量
const int W = 150;

// 物品结构体，包含重量、价值和单位价值
struct Item {
    int weight;
    int value;
    double unitValue;  // 单位价值 = 价值/重量
    int index;         // 原始物品索引
};

// 物品数组
Item items[N] = {
    {35, 10, 0.0, 0},
    {30, 40, 0.0, 1},
    {60, 30, 0.0, 2},
    {50, 50, 0.0, 3},
    {40, 35, 0.0, 4},
    {10, 40, 0.0, 5},
    {25, 30, 0.0, 6}
};

// 比较函数，按单位价值降序排序
bool compare(const Item& a, const Item& b) {
    return a.unitValue > b.unitValue;
}

int main() {
    // 计算每个物品的单位价值
    for (int i = 0; i < N; i++) {
        items[i].unitValue = (double)items[i].value / items[i].weight;
    }

    // 按单位价值降序排序
    sort(items, items + N, compare);

    int totalValue = 0;      // 总价值
    int remainingWeight = W; // 剩余容量
    bool selected[N] = {false}; // 记录被选中的物品

    // 贪心选择：优先选择单位价值高的物品
    for (int i = 0; i < N && remainingWeight > 0; i++) {
        // 如果当前物品可以完整放入
        if (items[i].weight <= remainingWeight) {
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
            selected[items[i].index] = true;
            cout << "选择物品 " << (items[i].index + 1) 
                 << "（重量: " << items[i].weight 
                 << ", 价值: " << items[i].value << "）" << endl;
        }
    }

    cout << "最大价值（贪心近似解）: " << totalValue << endl;
    cout << "选择的物品编号: ";
    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;

    return 0;
}