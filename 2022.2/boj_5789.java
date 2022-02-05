import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int n = input.nextInt();
        String ans = "";
        
        for(int i=0; i<n; i++){
            String str = input.next();
            int s = str.length()/2;
            if(str.charAt(s-1) == str.charAt(s)) ans = "Do-it";
            else ans = "Do-it-Not";
            System.out.println(ans);
        }
    }
}
