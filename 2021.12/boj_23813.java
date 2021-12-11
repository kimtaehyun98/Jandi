import java.math.BigInteger;
import java.util.Scanner;
import static java.lang.Math.max;

public class Main {
    
    public static void main(String[] args) {
    
       Scanner input = new Scanner(System.in);
        
        BigInteger n = input.nextBigInteger();
        BigInteger cmp = n;
        
        boolean flag = false;
        BigInteger sum = new BigInteger("0");
        while(true){
            if(flag && cmp.equals(n)) break;
            if(flag == false) flag = true;
            String s = n.toString();
            n = new BigInteger(s.charAt(s.length() -1) + s.substring(0, s.length()-1));
            sum = sum.add(n);
        }
    
        System.out.println(sum);
    }
}
