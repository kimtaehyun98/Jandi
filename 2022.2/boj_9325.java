import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int t = input.nextInt();
        
        for(int i=0; i<t; i++){
            
            int ans = input.nextInt();
            
            int n = input.nextInt();
            
            for(int k=0; k<n; k++){
                int q = input.nextInt();
                int p = input.nextInt();
                ans += (p*q);
            }
    
            System.out.println(ans);
        }
    }
}
