package JAVA;
import java.util.*;
public class pattern {
    public static void main(String arvg[]){
        Scanner myobj = new Scanner(System.in);
        int n = myobj.nextInt();
        myobj.close();

        for(int i = 0 ; i <= n ; i++){
            for(int j = 0  ; j < i; j++){
                System.out.print("* ");
            }
            System.out.println("");
        }
    }

}