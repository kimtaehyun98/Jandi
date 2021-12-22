import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        String str = "", cmp = "";
        
        while(true){
            if(str.equals("E-N-D")) break;
            str = input.next();
            String temp = "";
            for(int i=0; i<str.length(); i++){
                char c = str.charAt(i);
                if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '-' ) temp += c;
            }
            if(cmp.length() < temp.length()) cmp = temp;
        }
    
        System.out.println(cmp.toLowerCase());
    }
}
