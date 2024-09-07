package Basic;
import java.util.Scanner;
public class Salary {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);

        System.out.print("Enter Base Salary : ");
        int BaseSalary = myObj.nextInt();
        myObj.close();

        float da = BaseSalary * 15 / 100;
        float hra = BaseSalary * 10 / 100;

        System.out.println(BaseSalary + da + hra);
    }
}
