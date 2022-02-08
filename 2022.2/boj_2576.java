import java.util.Scanner;

public class Main {
    
    public static int min(int a, int b){
        if(a < b) return a;
        else return b;
    }
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int sum = 0, m = 101;
        for(int i=0; i<7; i++){
            int n = input.nextInt();
            if(n % 2 != 0) {
                sum += n;
                m = min(n, m);
            }
        }
        if(sum == 0) System.out.println(-1);
        else{
            System.out.println(sum);
            System.out.println(m);
        }
    }
}
