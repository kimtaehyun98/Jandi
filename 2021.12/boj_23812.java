import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
    
        for(int i=0; i<5*n; i++) {
            for (int j = 0; j < 5 * n; j++) {
                if (i / n != 1 && i / n != 3 && 1 <= j / n && j / n <= 3) System.out.print(" ");
                else System.out.print("@");
            }
            System.out.println();
        }
    }
}
