import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        input.nextLine();
        for(int i=0; i<n; i++){
            String str = input.nextLine();
            str += " ";
            String temp = "";
            ArrayList<String> arr = new ArrayList<String>();
            for(int k=0; k<str.length(); k++){
                char c = str.charAt(k);
                if(c == ' ') {
                    arr.add(temp);
                    temp = "";
                }
                else temp += c;
            }
            for(int k=2; k<arr.size(); k++){
                System.out.print(arr.get(k) + " ");
            }
            System.out.println(arr.get(0) + " " + arr.get(1));
        }
       
    }
}
