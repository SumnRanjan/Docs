package ImpQuestion;

import java.util.Scanner;

public class Ascii {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a character: ");
        char chr = scanner.next().charAt(0);
        scanner.close();

        int ascii = chr;
        System.out.println("ASCII Value of " + chr + " is " + ascii);
    }
}
