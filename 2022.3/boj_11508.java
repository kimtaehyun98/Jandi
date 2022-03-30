import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        ArrayList<Integer>arr = new ArrayList<Integer>();
        
        for(int i=0; i<n; i++){
            int c = input.nextInt();
            arr.add(c);
        }
        
        Collections.sort(arr, Collections.reverseOrder());
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(i % 3 == 2) continue;
            ans += arr.get(i);
        }
    
        System.out.println(ans);
    }
}
