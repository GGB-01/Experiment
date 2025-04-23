package com.study3;
import java.util.ArrayList;
import java.util.List;

public class ActivitySelection {
    public static List<Integer> selectActivities(int[] s, int[] f) {
        int n = s.length;
        List<Integer> selectedActivities = new ArrayList<>();
        // 第一个活动总是被选择
        selectedActivities.add(0);
        int lastEndTime = f[0];
        for (int i = 1; i < n; i++) {
            // 如果当前活动的开始时间大于等于上一个被选择活动的结束时间
            if (s[i] >= lastEndTime) {
                selectedActivities.add(i);
                lastEndTime = f[i];
            }
        }
        return selectedActivities;
    }

    public static void main(String[] args) {
        int[] s = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
        int[] f = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

        List<Integer> result = selectActivities(s, f);
        System.out.println("选择的活动索引为:");
        for (int index : result) {
            System.out.print(index + " ");
        }
    }
}