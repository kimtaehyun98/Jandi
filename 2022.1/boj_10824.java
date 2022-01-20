import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        String a = input.next();
        String b = input.next();
        String c = input.next();
        String d = input.next();
    
        BigInteger x = new BigInteger(a+b);
        BigInteger y = new BigInteger(c+d);
        
        System.out.println(x.add(y));
        
    }
}
