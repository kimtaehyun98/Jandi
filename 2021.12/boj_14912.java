import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        int x = input.nextInt();
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            String temp = Integer.toString(i);
            for(int k=0; k<temp.length(); k++){
                int t = temp.charAt(k) - '0';
                if(t == x) ans++;
            }
        }
    
        System.out.println(ans);
    }
}
