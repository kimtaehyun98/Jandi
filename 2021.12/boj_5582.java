import java.util.Scanner;
import static java.lang.Math.*;

public class Main {
    
    public static int dp[][];
    
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        
        String a = input.nextLine();
        String b = input.nextLine();
    
        int n = a.length(), m = b.length();
        
        dp = new int[n][m];
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a.charAt(i) == b.charAt(j)) {
                    if(i != 0 && j != 0) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        System.out.println(ans);
    }
}
