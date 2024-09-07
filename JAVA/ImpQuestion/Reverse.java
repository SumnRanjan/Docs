package ImpQuestion;

import java.util.Scanner;

public class Reverse {

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter  Str : ");
        String rev = myObj.nextLine();

        myObj.close();

        StringBuilder reve = new StringBuilder();

        reve.append(rev);
        reve.reverse();

        System.out.print(reve);
    }
}
