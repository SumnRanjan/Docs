package ImpQuestion;

import java.util.Scanner;

public class Prime {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Number : ");
        int num = myObj.nextInt();
        myObj.close();

        if(isPrime(num)){
            System.out.print("Is a Prime Number");
        } else{
            System.out.print("Not a Prime Number");
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
