import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        int a_x = input.nextInt();
        int a_y = input.nextInt();
        int b_x = input.nextInt();
        int b_y = input.nextInt();
        
        int a_c = a_y/b_x;
        if(a_y % b_x != 0) a_c++;
        int b_c = b_y/a_x;
        if(b_y % a_x != 0) b_c++;
        
        String ans;
        if(a_c > b_c) ans = "PLAYER A";
        else if(a_c < b_c) ans = "PLAYER B";
        else ans = "DRAW";
    
        System.out.println(ans);
    }
}
