import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        long n = input.nextLong();
        long m = input.nextLong();
        int ans = n == m ? 1 : 0;
        System.out.println(ans);
    }
}
