import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        int t = input.nextInt();
        int sum = 0;
        
        for(int i=0; i<t; i++){
            String n = input.next();
            
            sum = Integer.parseInt(n);
            int mul = 1;
            for(int k=0; k<n.length(); k++){
                sum += (n.charAt(k) - '0') * mul;
                mul *= 10;
            }
            
            String str = Integer.toString(sum);
            
            int s = str.length();
            boolean check = true;
            for(int j=0; j<s/2; j++){
                if(str.charAt(j) != str.charAt(s-j-1)){
                    check = false;
                }
            }
    
            if(check) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
