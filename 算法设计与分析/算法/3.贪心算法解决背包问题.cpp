// 计算单位价值：对每个物品，计算其单位价值v(i)/w(i)。
// 物品排序：将物品按单位价值从高到低排序。
// 装包过程：依次尝试把物品放入背包。若物品重量小于等于背包剩余容量，就将该物品全部放入；
// 若物品重量大于背包剩余容量，按背包剩余容量的比例装入部分该物品，直至背包被装满。

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
};

// 物品数组
Item items[N] = {
    {35, 10, 0.0},
    {30, 40, 0.0},
    {60, 30, 0.0},
    {50, 50, 0.0},
    {40, 35, 0.0},
    {10, 40, 0.0},
    {25, 30, 0.0}
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

    double totalValue = 0.0;  // 总价值
    int remainingWeight = W;  // 剩余容量

    // 贪心选择：优先选择单位价值高的物品
    for (int i = 0; i < N && remainingWeight > 0; i++) {
        // 如果当前物品可以完整放入
        if (items[i].weight <= remainingWeight) {
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
            cout << "放入物品 " << (i + 1) 
                 << "（重量: " << items[i].weight 
                 << ", 价值: " << items[i].value << "）" << endl;
        } else {
            // 否则放入物品的一部分
            double fraction = (double)remainingWeight / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << "放入物品 " << (i + 1) 
                 << " 的 " << fraction * 100 << "% "
                 << "（重量: " << remainingWeight 
                 << ", 价值: " << items[i].value * fraction << "）" << endl;
            remainingWeight = 0;  // 背包已满
        }
    }

    cout << "最大价值为: " << totalValue << endl;
    return 0;
}