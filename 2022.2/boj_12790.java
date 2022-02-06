import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int t = input.nextInt();
        
        int hp, mp, at, df, a, b, c, d;
        
        for(int i=0; i<t; i++){
            hp = input.nextInt();
            mp = input.nextInt();
            at = input.nextInt();
            df = input.nextInt();
            a = input.nextInt();
            b = input.nextInt();
            c = input.nextInt();
            d = input.nextInt();
            hp += a; mp += b; at += c; df += d;
            if(hp<1) hp = 1;
            if(mp<1) mp = 1;
            if(at<0) at = 0;
            System.out.println(hp + 5*mp + 2*at + 2*df);
        }
    }
}
