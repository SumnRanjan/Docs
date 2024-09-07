package JAVA;

import java.util.*;

public class TwoDArr {
    public static void main(String[] arvg) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter the Row : ");
        int r = myObj.nextInt();
        System.out.print("Enter the Col : ");
        int c = myObj.nextInt();

        int[][] matrix = new int[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = myObj.nextInt();
            }
        }

        // print 2d matrix
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println("");
        }

        // wave print

        for (int cols = 0; cols < r; cols++) {

            if ((cols & 1) == 0) {
                for (int i = 0; i < r; i++) {
                    System.out.print(matrix[i][cols] + " ");
                }
            } else {
                for (int i = r - 1; i >= 0; i--) {
                    System.out.print(matrix[i][cols] + " ");
                }

            }

        }

        myObj.close();
    }
}
