import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
    
        for(int i=0; i<n; i++){
            for(int j=0; j<5*n; j++){
                System.out.print("@");
            }
            System.out.println();
        }
        
        for(int i=0; i<3*n; i++){
            for(int j=0; j<5*n; j++){
                if(1 <= j/n && j/n <= 3) System.out.print(" ");
                else System.out.print("@");
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
