package com.kaseknife95;

import java.util.Arrays;

public class ArrayHelper {
    public static <T> T[] push(T[] arr, T item) {
        T[] tmp = Arrays.copyOf(arr, arr.length + 1);
        tmp[tmp.length - 1] = item;
        return tmp;
    }

    public static <T> T[] pop(T[] arr) {
        T[] tmp = Arrays.copyOf(arr, arr.length - 1);
        return tmp;
    }
    public static Student[] removeElement(Student[] arr, int removedIdx) {
        
        Student[] arr2 = new Student[arr.length - 1];

        // Copy the elements except the index
        // from original array to the other array
        for (int i = 0, k = 0; i < arr.length; i++) {
            if (i == removedIdx)
                continue;
            
              arr2[k++] = arr[i];
        }

        return arr2;
    }
}