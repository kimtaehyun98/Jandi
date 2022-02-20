import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int a = input.nextInt();
        int b = input.nextInt();
        
        // 샘플
        boolean ca = true, cb = true;
        for(int i=0; i<a; i++){
            int x = input.nextInt();
            int y = input.nextInt();
            if(x != y) ca = false;
        }
        
        // 시스템
        for(int i=0; i<b; i++){
            int x = input.nextInt();
            int y = input.nextInt();
            if(x != y) cb = false;
        }
        
        String ans = "";
        if(ca && cb) ans = "Accepted";
        else if(ca) ans = "Why Wrong!!!";
        else ans = "Wrong Answer";
    
        System.out.println(ans);
    }
}
