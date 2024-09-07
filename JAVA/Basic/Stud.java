package Basic;
import java.util.Scanner;

public class Stud {
    public static void main(String[] args) {

        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter First Name: ");
        String firstName = myObj.nextLine();

        System.out.print("Enter Last Name: ");
        String lastName = myObj.nextLine();

        System.out.print("Enter Mail ID: ");
        String mail = myObj.nextLine();

        System.out.print("Enter Mobile Number: ");
        long number = myObj.nextLong();

        System.out.print("Enter Age: ");
        int age = myObj.nextInt();

        System.out.print("Enter ID: ");
        int id = myObj.nextInt();

        System.out.print("Enter Height: ");
        float height = myObj.nextFloat();

        myObj.close();

        System.out.println("First Name: " + firstName);
        System.out.println("Last Name: " + lastName);
        System.out.println("Mail ID: " + mail);
        System.out.println("Mobile Number: " + number);
        System.out.println("Age: " + age);
        System.out.println("ID: " + id);
        System.out.println("Height: " + height);

    }
}
