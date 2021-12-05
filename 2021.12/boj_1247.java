import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        
        for(int i=0; i<3; i++){
            int n = input.nextInt();
            BigInteger sum = new BigInteger("0");
            for(int k=0; k<n; k++){
                sum = sum.add(input.nextBigInteger());
            }
            int cmp = sum.compareTo(BigInteger.valueOf(0));
            if(cmp == 0) System.out.println("0");
            else if(cmp == 1) System.out.println("+");
            else System.out.println("-");
        }
        
    }
}
