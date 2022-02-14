import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int n = input.nextInt();
        String str = input.next();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += str.charAt(i) - 'A' + 1;
        }
        System.out.println(ans);
    }
}
