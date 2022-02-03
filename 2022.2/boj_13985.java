import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        String str = input.nextLine();
        
        String ans = "";
        if((str.charAt(0)-'0') + (str.charAt(4) - '0') == (str.charAt(8) - '0')) ans = "YES";
        else ans = "NO";
    
        System.out.println(ans);
    }
}
