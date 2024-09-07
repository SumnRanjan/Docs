package JAVA;

import java.util.*;

public class array {

    public static void main(String[] arvg) {
        Scanner myObj = new Scanner(System.in);

        System.out.print("Enter the Size of Array : ");
        int n = myObj.nextInt();

        int[] array = new int[n];

        // User Input of Array
        for (int i = 0; i < n; i++) { 
            array[i] = myObj.nextInt();
        }

        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
        myObj.close();
    }
}
