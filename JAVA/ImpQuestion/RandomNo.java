package ImpQuestion;

import java.util.Scanner;

public class RandomNo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the minimum value: ");
        int min = scanner.nextInt();

        System.out.print("Enter the maximum value: "); 
        int max = scanner.nextInt();

        double a = Math.random()*(max - min + 1) + min;

        System.out.println(a);

        System.out.println("Random Number Between " + max + " & " + min + " is ");

        int b = (int)(Math.random()*(max - min + 1) + min);

        System.out.println(b);

        scanner.close();
    }
}
