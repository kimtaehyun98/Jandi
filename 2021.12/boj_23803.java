import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        
        for(int i=0; i<4*n; i++){
            for(int j=0; j<n; j++){
                System.out.print("@");
            }
            System.out.println();
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<5*n; j++){
                System.out.print("@");
            }
            System.out.println();
        }
    }
}
