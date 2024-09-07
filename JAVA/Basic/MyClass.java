package Basic;
import java.util.Scanner;

public class MyClass {
    public static void main(String[] args) {
        // @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Your First Name : ");
        String firstName = scanner.nextLine();

        System.out.print("Enter Your Last Name : ");
        String lastName = scanner.nextLine();

        System.out.print("Enter Your Number : ");
        String age = scanner.nextLine();

        scanner.close();
        System.out.print(firstName + " ");
        System.out.print(lastName + " ");
        System.out.print(age);
    }
}
