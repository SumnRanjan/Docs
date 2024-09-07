package ImpQuestion;


import java.util.Scanner;

public class Fibo {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter  Number : ");
        int n = myObj.nextInt();
        myObj.close();
        int a = 0;
        int b = 1;
        int sum;
        System.out.print(a + " " + b);

        for (int i = 0; i < n - 2; i++) {
            sum = a + b;
            System.out.print(" " + sum);
            a = b;
            b = sum;

        }

    }
}
