package Basic;
// public class ForLoop {
//     public static void main(String[] args) {
//         int n = 10;
//         for(int i = 0 ; i <= n ; i++){
//             if(i % 2 == 0 )
//             System.out.print(i + " ");
//         }
//     }
// }

//nested loop
public class ForLoop {
    public static void main(String[] args) {
        int n = 3;
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= n ; j++){
                System.out.print("*" + " ");
            }
            System.out.println("");
        }
    }
}

// foreach 
// foreach(type VariableName : array){
//     //code
// }