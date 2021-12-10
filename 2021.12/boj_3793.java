import java.util.Scanner;
import static java.lang.Math.max;

public class Main {
    
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        while(input.hasNext()){
            String a = input.next();
            String b = input.next();
            
            int n = a.length(), m = b.length();
            int lcs[][] = new int[n + 1][m + 1];
    
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    if(a.charAt(i - 1) == b.charAt(j - 1)){
                        lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    }
                    else{
                        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                    }
                }
            }
    
            System.out.println(lcs[n][m]);
        }
    }
}
