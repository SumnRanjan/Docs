package Basic;
import java.util.Scanner;

public class Ove {
    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        // System.out.println("Enter Your Name");
        // String name = scanner.nextLine();
        // System.out.println(name);

        // final int a = 5;
        // a = 8;
        // System.out.println(a);

        // String carName = "Volvo";
        // System.out.println(carName);

        // int x = 5;
        // int y = 6;

        // System.out.println(x+y);
        // int x = 5 , y = 6 , z = 6;
        // System.out.println(x+y+z);

        // char v = 's';
        // int s = (int) v;
        // System.out.println(s);
        // System.out.println(v);

        // System.out.println(
        // Math.max(5, 8));

        // Math.min(0, 0);
        // Math.random()

        // if - else
        // int a = 0;
        // if (a > 0) {
        // System.out.println("positve");
        // } else if (a == 0) {
        // System.out.println("zero");
        // } else{
        // System.out.println("negative");
        // }

        // switch

        System.out.println("Enter the Day : ");
        int day = scanner.nextInt();
        scanner.close();
        

        switch (day) {
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
            case 7:
                System.out.println("Sunday");
                break;
            default:
                System.out.println("Invalid");
                break;
        }
    }
}
