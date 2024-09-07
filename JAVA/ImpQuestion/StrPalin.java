package ImpQuestion;

import java.util.Scanner;

public class StrPalin {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Str: ");
        String rev = myObj.nextLine();
        myObj.close();

        StringBuilder reve = new StringBuilder();
        reve.append(rev);
        reve.reverse();

            if (rev.equals(reve.toString())) {
                System.out.print("Valid Palindrome");
            } else {
                System.out.println("Invalid Palindrome");
            }
        }
}
