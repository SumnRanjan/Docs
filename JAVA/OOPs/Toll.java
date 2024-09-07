package OOPs;

import java.util.*;

class Toll {
    private int TotalCar = 0;
    private int tax = 0;

    public void CarPassing(int money) {
        tax = tax + money;
        TotalCar++;
    }

    public void totalCarPassed() {
        System.out.println("Total car Passed: " + TotalCar);
    }

    public void totalMoneyCollected() {
        System.out.println("Total Money Collected : " + tax);
    }
}

class Package {
    public static void main(String[] args) {
        Toll t1 = new Toll();
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        while (true) {

            System.out.print("Enter the money: ");
            int n = scanner.nextInt();
            t1.CarPassing(n);
            t1.totalCarPassed();
            t1.totalMoneyCollected();
        }

    }
}