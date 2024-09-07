import java.util.*;

public class occ {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of Array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter all the elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the element of which you want to count the number of occurrences: ");
        int element = sc.nextInt();

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == element) {
                count++;
            }
        }

        System.out.println("Number of Occurrence of " + element + " is: " + count);
        sc.close();
    }
}
