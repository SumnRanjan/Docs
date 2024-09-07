import java.util.*;

public class second {
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of Array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter all the elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        sc.close();

        Arrays.sort(arr);

        System.out.println(arr[1]);
    }
}
