package ImpQuestion;

import java.util.Scanner;

public class Ascii2char {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a Number: ");
        int num = scanner.nextInt();
        scanner.close();

        char ch = (char) num;
        
        System.out.println("The character for ASCII code " + num + " is '" + ch + "'");
    }
}
