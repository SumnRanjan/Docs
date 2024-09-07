import java.util.*;

public class max {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] array = new int[size];

        System.out.println("Enter the elements of the array:");

        for (int i = 0; i < size; i++) {  
            array[i] = scanner.nextInt();
        }

        int max = -1;
        int smax = -1;

        for (int i = 0; i < size; i++) {
            if(max < array[i]){
                smax = max;
                max = array[i];
            }

            else if (array[i] < max && array[i] > smax){
                smax = array[i];
            }
        }

        System.out.println("max :" + max + " smax :" + smax);

        scanner.close();
    }

}
