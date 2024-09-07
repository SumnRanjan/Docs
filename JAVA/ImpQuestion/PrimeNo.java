package ImpQuestion;

import java.util.Scanner;

public class PrimeNo {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Number : ");
        int start = myObj.nextInt();
        System.out.print("Enter Number : ");
        int end = myObj.nextInt();
        myObj.close();

        for(int i = start ; i <= end ; i++){
            if (isPrime(i)) {
                System.out.println(i);
            }
        }
    }

    public static boolean isPrime(int n){
        if (n <= 1) {
            return false;
        } 

        for(int i = 2 ; i < Math.sqrt(n) ; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}
