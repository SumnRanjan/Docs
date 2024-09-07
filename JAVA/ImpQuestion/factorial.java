package ImpQuestion;

import  java.util.*;

public class factorial {
    public static void main(String[] args) {

        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter  Number : ");
        int n = myObj.nextInt();
       
        
        int result =  1;

        for(int i = 1 ; i <= n ; i++){
            result *= i;
        }
        
        System.out.println("factorial of " + n + " is : " + result);
        myObj.close();
    }
}
