package String;

import java.util.*;

public class StudentInfo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        

        System.out.print("Enter First Name: ");
        String fname = scanner.nextLine();
        
        System.out.print("Enter Last Name: ");
        String lname = scanner.nextLine();
        
        System.out.print("Enter Roll Number: ");
        String rollNo = scanner.nextLine();
        
        System.out.print("Enter Branch: ");
        String branch = scanner.nextLine();
        
        System.out.print("Enter Semester: ");
        String semester = scanner.nextLine();
        
        scanner.close();
        
        // 1. Append
        String fullName = fname + " " + lname;
        StringBuilder stringBuilder = new StringBuilder(fullName);
        stringBuilder.append(" - Roll No: ").append(rollNo);
        stringBuilder.append(", Branch: ").append(branch);
        stringBuilder.append(", Semester: ").append(semester);
        String appendedString = stringBuilder.toString();
        System.out.println("Appended String: " + appendedString);
        
        // 2. Join
        String joinedString = String.join(", ", fname, lname, rollNo, branch, semester);
        System.out.println("Joined String: " + joinedString);
        
        // 3. Format
        String formattedString = String.format("Student: %s %s, Roll No: %s, Branch: %s, Semester: %s", fname, lname, rollNo, branch, semester);
        System.out.println("Formatted String: " + formattedString);
        
        // 4. StringJoiner
        StringJoiner stringJoiner = new StringJoiner(", ");
        stringJoiner.add(fname).add(lname).add(rollNo).add(branch).add(semester);
        String joinedUsingStringJoiner = stringJoiner.toString();
        System.out.println("StringJoiner Output: " + joinedUsingStringJoiner);
    }
}

