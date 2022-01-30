import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        BigInteger n = input.nextBigInteger();
        BigInteger r = input.nextBigInteger();
        
        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        
        BigInteger ans = n.add(one);
        if(!r.equals(one)) {
            ans = ans.add((r.subtract(one)).multiply(two));
        }
    
        System.out.println(ans);
    }
}
