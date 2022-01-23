import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int a, b, c, d;
        while (true) {
            a=input.nextInt();
            b=input.nextInt();
            c=input.nextInt();
            d=input.nextInt();
            if (a == 0 && b == 0 && c == 0 && d == 0) break;
            System.out.print(c-b);
            System.out.print(" ");
            System.out.println(d-a);
        }
    }
}
