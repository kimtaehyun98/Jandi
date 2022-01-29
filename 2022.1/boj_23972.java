import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        long k = input.nextLong();
        long n = input.nextLong();
        
        if(n == 1) System.out.println(-1);
        else{
            long temp = (k * n) % (n - 1) != 0 ? 1 : 0;
            System.out.println((k * n) / (n - 1) + temp);
        }
    }
}
