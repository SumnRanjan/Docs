package Basic;
import java.util.Scanner;

public class Arthmatic {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);

        System.out.print("Enter the First : ");
        int first = myObj.nextInt();

        System.out.print("Enter the Second : ");
        int second = myObj.nextInt();

        System.out.print("Enter the Operator: ");
        char operator = myObj.next().charAt(0);

        myObj.close();

        switch (operator) {
            case '+':
                System.out.println("Result : " + first + second);
                break;
            case '-':
                System.out.println("Result : " + (first - second));
                break;
            case '*':
                System.out.println("Result : " + first * second);
                break;
            case '/':
                System.out.println("Result : " + first / second);
                break;
            case '%':
                System.out.print("Result : " + first % second);
                break;

            default:
                System.out.println("Invalid Input");
                break;
        }

    }
}
