package JAVA;

import java.util.*;
public class NextFibonacci {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("enter num: ");
        int num = sc.nextInt();
        sc.close();

        int a = 0;
        int b = 1;
        if(num <= 1){
            System.out.println("1");
        }
        while(b < num)
        {
            int temp = b;
            b = a+b;
            a = temp;
        }
        System.out.println(b);
    }
}