import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int two = 0, e = 0;
        int size = input.nextInt();
        String str = input.next();
        for(int i=0; i<size; i++) {
            if(str.charAt(i) == 'e') e++;
            else two++;
        }
        String ans;
        if(e == two) ans = "yee";
        else if(e > two) ans = "e";
        else ans = "2";
        System.out.println(ans);
    }
}
