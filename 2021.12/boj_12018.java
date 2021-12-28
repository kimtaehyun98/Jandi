import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        int m = input.nextInt();
        
        ArrayList<Integer>ans = new ArrayList<Integer>();
        
        for(int i=0; i<n; i++){
            int p = input.nextInt();
            int l = input.nextInt();
    
            ArrayList<Integer>arr = new ArrayList<Integer>();
            
            for(int k=0; k<p; k++){
                arr.add(input.nextInt());
            }
            
            Collections.sort(arr, Collections.reverseOrder());
            
            if(l > p) ans.add(1);
            else ans.add(arr.get(l-1));
        }
        
        Collections.sort(ans);
        int cnt = 0;
        for(int i=0; i<ans.size(); i++){
            if(m >= ans.get(i)) {
                cnt++;
                m -= ans.get(i);
            }
        }
    
        System.out.println(cnt);
    }
}
