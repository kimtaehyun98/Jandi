import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        int a [] = new int[9];
        int b [] = new int[9];
        for(int i=0; i<9; i++){
            a[i] = input.nextInt();
        }
        for(int i=0; i<9; i++){
            b[i] = input.nextInt();
        }
        
        int sa = 0, sb = 0;
        boolean stop = false;
        for(int i=0; i<9; i++){
            sa += a[i];
            if(sa > sb) {
                stop = true;
                break;
            }
            sb += b[i];
        }
        String ans = stop ? "Yes" : "No";
        System.out.println(ans);
    }
}
