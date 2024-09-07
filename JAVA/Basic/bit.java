package Basic;

import java.util.*;

public class bit {
    public static void main(String[] args) {
        Scanner myobj  = new Scanner(System.in);
        int n = myobj.nextInt();
        int m = myobj.nextInt();

        myobj.close();

        System.out.println(n|m);
        System.out.println(n&m);
        System.out.println(n^m);
        System.out.println(~n);
        System.out.println(n<<2); //left shift
        System.out.println(n>>2); //right shift
        // System.out.println(~((21^17)|9));
    }
}
