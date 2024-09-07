package Method;

import java.util.Scanner;

public class Add {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);

        System.out.print("Enter the First number: ");
        int num = myObj.nextInt();

        System.out.print("Enter the second number: ");
        int num1 = myObj.nextInt();

        System.out.print("Enter the Third number: ");
        int num2 = myObj.nextInt();

        myObj.close();

        System.out.println(PlusMethod(num, num1));
        System.out.println(PlusMethod(num, num1, num2));
        
    }

    static int PlusMethod(int x, int y) {
        return x + y;
    }

    static int PlusMethod(int x, int y, int z) {
        return x + y + z;
    }
}  