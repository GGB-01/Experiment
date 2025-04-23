package com.study4;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Item {
    int index;
    int profit;
    int weight;
    double bound;

    Item(int index, int profit, int weight, double bound) {
        this.index = index;
        this.profit = profit;
        this.weight = weight;
        this.bound = bound;
    }
}

public class KnapsackBranchAndBound {
    private int[] p;
    private int[] w;

    // 计算上界函数
    private double calculateBound(Item item, int C, int n) {
        int remainingWeight = C - item.weight;
        double bound = item.profit;
        int j = item.index + 1;
        while (j < n && w[j] <= remainingWeight) {
            remainingWeight -= w[j];
            bound += p[j];
            j++;
        }
        if (j < n) {
            bound += (double) p[j] / w[j] * remainingWeight;
        }
        return bound;
    }

    // 分支限界算法核心
    public void solveKnapsack(int[] p, int[] w, int C) {
        this.p = p;
        this.w = w;
        int n = p.length;
        int maxProfit = 0;
        List<Integer> bestSolution = new ArrayList<>();

        PriorityQueue<Item> queue = new PriorityQueue<>((a, b) -> Double.compare(b.bound, a.bound));
        Item root = new Item(-1, 0, 0, calculateBound(new Item(-1, 0, 0, 0), C, n));
        queue.add(root);

        while (!queue.isEmpty()) {
            Item current = queue.poll();
            if (current.index == n - 1) {
                if (current.profit > maxProfit) {
                    maxProfit = current.profit;
                    bestSolution = getSolution(current, n);
                }
            } else {
                // 左子节点（放入物品）
                int newWeight = current.weight + w[current.index + 1];
                int newProfit = current.profit + p[current.index + 1];
                if (newWeight <= C) {
                    Item leftChild = new Item(current.index + 1, newProfit, newWeight, calculateBound(new Item(current.index + 1, newProfit, newWeight, 0), C, n));
                    queue.add(leftChild);
                }

                // 右子节点（不放入物品）
                Item rightChild = new Item(current.index + 1, current.profit, current.weight, calculateBound(new Item(current.index + 1, current.profit, current.weight, 0), C, n));
                queue.add(rightChild);
            }
        }

        System.out.println("最优值: " + maxProfit);
        System.out.println("最优解: " + bestSolution);
    }

    // 根据最终节点还原最优解
    private List<Integer> getSolution(Item item, int n) {
        List<Integer> solution = new ArrayList<>();
        Item current = item;
        for (int i = 0; i < n; i++) {
            if (i > current.index) {
                solution.add(0);
            } else if (i == current.index) {
                solution.add(1);
            } else {
                Item parent = getParent(current, i, n);
                if (parent.weight + w[i] == current.weight) {
                    solution.add(1);
                } else {
                    solution.add(0);
                }
            }
        }
        return solution;
    }

    // 找到指定索引的父节点
    private Item getParent(Item item, int index, int n) {
        PriorityQueue<Item> queue = new PriorityQueue<>((a, b) -> Double.compare(b.bound, a.bound));
        queue.add(item);
        while (!queue.isEmpty()) {
            Item current = queue.poll();
            if (current.index == index) {
                return current;
            }
            if (current.index > index) {
                if (current.index - 1 >= 0) {
                    Item leftChild = new Item(current.index - 1, current.profit - p[current.index - 1], current.weight - w[current.index - 1], 0);
                    Item rightChild = new Item(current.index - 1, current.profit, current.weight, 0);
                    queue.add(leftChild);
                    queue.add(rightChild);
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        int[] p = {9, 10, 7, 4};
        int[] w = {3, 5, 2, 1};
        int C = 7;
        KnapsackBranchAndBound knapsack = new KnapsackBranchAndBound();
        knapsack.solveKnapsack(p, w, C);
    }
}