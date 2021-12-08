import java.util.Scanner;
import static java.lang.Math.*;

public class Main {
    
    public static int dp[][];
    
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        
        int arr[] = new int[n];
        
        for(int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        
        int m = 0, y = 0;
        for(int i = 0; i < n; i++) {
            y += ((arr[i]/30) + 1) * 10;
            m += ((arr[i]/60) + 1) * 15;
        }
        
        if(y < m) {
            System.out.println("Y " + y);
        }
        else if(y > m) {
            System.out.println("M " + m);
        }
        else {
            System.out.println("Y M " + y);
        }
    }
}
