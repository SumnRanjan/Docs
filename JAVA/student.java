import java.util.Scanner;

// write a program to implement interfaces class where all the input will be taken from the user
// where the first inerface class is university and it contain method name student details and other interfaces class name is department and a new class would be implemented from the interface classes  that is student .
// display the name of students and its roll number with the method declared in the interface university and also display the department name and department id with the method declared in the interface department.

public class student {
    @SuppressWarnings("resource")
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        int roll = sc.nextInt();
        String deptName = sc.next();
        int deptId = sc.nextInt();
        Student student = new Student(name, roll, deptName, deptId);
        student.studentDetails();
    }

    public interface University {
        void studentDetails();
    }

    public interface Department {
        void departmentDetails();
    }

    public static class Student implements University, Department {
        String name;
        int roll;
        String deptName;
        int deptId;

        public Student(String name, int roll, String deptName, int deptId) {
            this.name = name;
            this.roll = roll;
            this.deptName = deptName;
            this.deptId = deptId;
        }

        @Override
        public void studentDetails() {
            System.out.println("student name: " + name);
            System.out.println("student roll: " + roll);
            departmentDetails();
        }

        @Override
        public void departmentDetails() {
            System.out.println("department name: " + deptName);
            System.out.println("department id: " + deptId);
        }
    }
}
