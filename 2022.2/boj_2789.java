import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        String str = input.next();
        String ans = "";
        char arr[] = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'}; //  CAMBRIDGE
        for(int i=0; i<str.length(); i++){
            boolean stop = false;
            for(int k=0; k<9; k++){
                if(str.charAt(i) == arr[k]) {
                    stop = true;
                    break;
                }
            }
            if(stop) continue;
            else ans += str.charAt(i);
        }
        System.out.println(ans);
    }
}
