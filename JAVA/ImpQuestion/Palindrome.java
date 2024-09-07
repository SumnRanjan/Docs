package ImpQuestion;

import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Number: ");
        int num = myObj.nextInt();
        myObj.close();

        int temp = num;
        int rev = 0;

        while (temp != 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }

        if (rev == num) {
            System.out.print("Valid Palindrome");
        } else {
            System.out.println("Invalid Palindrome");
        }
    }
}
