import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static BigInteger [][] dp = new BigInteger[101][101];
    
    public static void main(String[] args) {
        for(int n = 1; n <= 100; n++){
            for(int m = 0; m <= n; m++){
                if(m == 0 || n == m) dp[n][m] = new BigInteger("1");
                else dp[n][m] = dp[n-1][m].add(dp[n-1][m-1]);
            }
        }
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        System.out.println(dp[n][m]);
    }
}
