//Function------
package Basic;
import java.util.Scanner;

public class Votes {
    static void Vote(int age) {
        if (age < 18) {
            System.out.print("You are Childern ");
        }

        else if (age >= 18 || age <= 100) {
            System.out.print("You Can Vote ");
        }

        else {
            System.out.print("Invalid Input");
        }
    }

    public static void main(String[] args) {

        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Your Age: ");
        int age = myObj.nextInt();

        myObj.close();

        Vote(age);

    }
}
