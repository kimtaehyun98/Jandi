import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        int ans = 5;
        if(n > 1){
            int prev = 7;
            for(int i = 0; i < n-1; i++){
                ans += prev;
                prev += 3;
                ans %= 45678;
            }
        }
        System.out.println(ans);
    }
}
