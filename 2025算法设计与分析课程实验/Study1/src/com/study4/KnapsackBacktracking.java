package com.study4;
import java.util.ArrayList;
import java.util.List;

public class KnapsackBacktracking {
    private int maxValue = 0;
    private List<Integer> bestSolution = new ArrayList<>();

    // 回溯算法核心函数
    private void backtrack(int[] p, int[] w, int C, int index, int currentWeight, int currentValue, List<Integer> currentSolution) {
        // 如果已经处理完所有物品或者背包已满，更新最优值和最优解
        if (index == p.length || currentWeight == C) {
            if (currentValue > maxValue) {
                maxValue = currentValue;
                bestSolution = new ArrayList<>(currentSolution);
            }
            return;
        }

        // 不放入当前物品
        backtrack(p, w, C, index + 1, currentWeight, currentValue, currentSolution);

        // 如果放入当前物品后不超过背包容量，则放入当前物品
        if (currentWeight + w[index] <= C) {
            currentSolution.add(1);
            backtrack(p, w, C, index + 1, currentWeight + w[index], currentValue + p[index], currentSolution);
            currentSolution.remove(currentSolution.size() - 1);
        }
    }

    // 对外接口，调用回溯算法并返回结果
    public void solveKnapsack(int[] p, int[] w, int C) {
        List<Integer> currentSolution = new ArrayList<>();
        backtrack(p, w, C, 0, 0, 0, currentSolution);
        System.out.println("最优值: " + maxValue);
        System.out.println("最优解: " + bestSolution);
    }

    public static void main(String[] args) {
        int[] p = {9, 10, 7, 4};
        int[] w = {3, 5, 2, 1};
        int C = 7;
        KnapsackBacktracking knapsack = new KnapsackBacktracking();
        knapsack.solveKnapsack(p, w, C);
    }
}