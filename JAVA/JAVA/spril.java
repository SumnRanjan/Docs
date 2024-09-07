package JAVA;

import java.util.*;

public class spril {
    public static void main(String[] arvg){
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Row : ");
        int r = myObj.nextInt();
        System.out.print("Enter Col : ");
        int c = myObj.nextInt();

        int[][] mat = new int[r][c];

        int totalEle = r * c;

        int startrow = 0;
        int endingcol = c - 1;
        int endingrow = r - 1;
        int startcol = 0;

        int count = 0;

        //User Input of 2D array
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                mat[i][j] = myObj.nextInt();
            }
        }

        //Spiral Print

        while (count < totalEle) {
            //startingRow 
            for(int i = startcol ; i <= endingcol && count < totalEle ; i++){
                System.out.print(mat[startrow][i] + " ");
                count++;
            }
            startrow++;

            //endingcol
            for(int i = startrow ; i <= endingrow && count < totalEle ; i++){
                System.out.print(mat[i][endingcol] + " ");
                count++;
            }
            endingcol--;

            //endingrow
            for(int i = endingcol ; i >= startcol && count < totalEle ; i--){
                System.out.print(mat[endingrow][i] + " ");
                count++;
            }
            endingrow--;

            //starting col
            for(int i = endingrow ; i >= startrow && count < totalEle ; i--){
                System.out.print(mat[i][startcol] + " ");
                count++;
            }
            startcol++;
        }

        myObj.close();
    }
}
