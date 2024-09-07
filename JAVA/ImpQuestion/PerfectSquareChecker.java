package ImpQuestion;

import java.util.Scanner;

public class PerfectSquareChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        double squareRoot = Math.sqrt(number);

        System.out.println(number);
        System.out.println(squareRoot);
        System.out.println((int)squareRoot);





        // if (squareRoot == (int) squareRoot) {
        //     System.out.println(number + " is a perfect square.");
        // } else {
        //     System.out.println(number + " is not a perfect square.");
        // }

        scanner.close();
    }
}
