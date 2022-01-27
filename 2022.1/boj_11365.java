import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        while(true) {
            String str = input.nextLine();
            if(str.equals("END")) break;
            for(int i=str.length() -1 ; i>=0; i--){
                System.out.print(str.charAt(i));
            }
            System.out.println();
        }
    }
}
