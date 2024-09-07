package JAVA;
import java.util.Scanner;

public class Kaprekar {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        int square = number * number;

        // Convert the square to a string
        String squareStr = Integer.toString(square);
        int len = squareStr.length();

        String leftPart = squareStr.substring(0, len / 2);
        String rightPart = squareStr.substring(len / 2);

        int leftNum = leftPart.isEmpty() ? 0 : Integer.parseInt(leftPart);
        int rightNum = Integer.parseInt(rightPart);

        if (leftNum + rightNum == number) {
            System.out.println(number + " is a Kaprekar number.");
        } else {
            System.out.println(number + " is not a Kaprekar number.");
        }

        scanner.close();
    }
}
