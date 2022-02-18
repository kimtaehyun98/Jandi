import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int n = input.nextInt();
        int cnt = 0;
        while(n!=1) {
            if(n%2 != 0) n-=1;
            n = n/2;
            cnt++;
        }
        
        System.out.println(1 << cnt);
    }
}
