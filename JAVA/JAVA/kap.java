package JAVA;

import java.util.*;

public class kap {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num = scanner.nextInt();
        int square = num * num;

       String squaresrt = Integer.toString(square);
       int len = squaresrt.length();

       String leftPart = squaresrt.substring(0, len/2);
       String rigthPart = squaresrt.substring(len /2);


       int left = squaresrt.isEmpty() ? 0 : Integer.parseInt(leftPart);
       int right = Integer.parseInt(rigthPart);


        if (left + right == num) {
            System.out.println("yes");
        } else {
            System.out.println("No");
        }

        scanner.close();

    }

}
