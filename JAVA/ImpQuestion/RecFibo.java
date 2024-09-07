package ImpQuestion;

import java.util.Scanner;

public class RecFibo {
    static int a = 0, b = 1, sum = 0;

    static void PrintFib(int n) {
        if (n > 0) {
            sum = a + b;
            a = b;
            b = sum;
            System.out.print(" " + sum);
            PrintFib(n - 1);
        }
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Number: ");
        int n = myObj.nextInt();
        myObj.close();
        System.out.print(a + " " + b);
        PrintFib(n - 2);
    }
}
