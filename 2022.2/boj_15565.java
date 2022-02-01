import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static int min(int a, int b){
        if(a < b) return a;
        else return b;
    }
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int n = input.nextInt();
        int k = input.nextInt();
        
        int arr[] = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = input.nextInt();
        }
        
        int s = 0, e = 0, cnt = 0, ans = 1000001;
        while(true){
            if(cnt >= k) {
                ans = min(ans, e - s);
                if(arr[s] == 1) cnt -= 1;
                s++;
            }
            else if(e == n) break;
            else{
                if(arr[e] == 1) cnt += 1;
                e++;
            }
        }
        if(ans == 1000001) ans = -1;
        System.out.println(ans);
    }
}
