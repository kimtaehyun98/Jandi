import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
    
        for(int i=0; i<5*n; i++){
            for(int j=0; j<5*n; j++){
                if((i/n == 1 || i/n == 3) && j/n == 4) break;
                else if(i/n == 2 && j/n == 3) break;
                
                if((i/n == 0 || i/n == 4) && 1 <= j/n && j/n <= 3) System.out.print(" ");
                else if((i/n == 1 || i/n == 3) && j/n != 0 && j/n != 3) System.out.print(" ");
                else if(i/n == 2 && 3 <= j/n && j/n <= 4) System.out.print(" ");
                else System.out.print("@");
            }
            System.out.println();
        }
    }
}
