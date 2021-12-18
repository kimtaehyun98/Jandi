import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
    
        for(int i=0; i<5*n; i++){
            for(int j=0; j<5*n; j++){
                if((i/n == 1 || i/n == 3 || i/n == 4) && j/n == 1) break;
                System.out.print("@");
            }
            System.out.println();
        }
    }
}
