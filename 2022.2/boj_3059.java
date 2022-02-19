import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int t = input.nextInt();
        
        for(int i=0; i<t; i++){
            String s = input.next();
            boolean check [] = new  boolean[26];
            for(int k=0; k<26; k++) check[k] = true;
            int ans = 2015;
            for(int k=0; k<s.length(); k++){
                int temp = s.charAt(k) - 'A';
                if(check[temp]){
                    check[temp] = false;
                    ans -= temp + 'A';
                }
            }
            System.out.println(ans);
        }
        
    }
}
