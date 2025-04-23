package com.study3;

import java.util.ArrayList;
import java.util.List;

public class OptimalLoading {
    public static List<Integer> optimalLoading(int c, int[] w) {
        int n = w.length;
        List<Integer> selectedContainers = new ArrayList<>();
        // 对集装箱重量进行排序，优先选择重量小的集装箱
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (w[i] > w[j]) {
                    int temp = w[i];
                    w[i] = w[j];
                    w[j] = temp;
                }
            }
        }
        int currentWeight = 0;
        for (int i = 0; i < n; i++) {
            if (currentWeight + w[i] <= c) {
                selectedContainers.add(i);
                currentWeight += w[i];
            }
        }
        return selectedContainers;
    }

    public static void main(String[] args) {
        int c = 70;
        int[] w = {20, 10, 26, 15};

        List<Integer> result = optimalLoading(c, w);
        System.out.println("选择的集装箱索引为:");
        for (int index : result) {
            System.out.print(index + " ");
        }
    }
}