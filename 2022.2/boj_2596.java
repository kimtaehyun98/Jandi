import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        String s = input.next();
        
        String [] arr = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
        String [] alpha = {"A", "B", "C", "D", "E", "F", "G", "H"};
        
        String ans = "";
        
        for(int i=0; i<n; i++){
            boolean stop = false;
            String temp = "";
            int one = 0;
            for(int a=0; a<8; a++){
                int cnt = 0;
                for(int k=0; k<6; k++){
                    if(arr[a].charAt(k) != s.charAt(k + i*6)) cnt++;
                }
                if(cnt == 0) {
                    stop = true;
                    ans += alpha[a];
                    break;
                }
                else if(cnt == 1){
                    temp = alpha[a];
                    one++;
                }
                else continue;
            }
            if(stop) continue;
            else {
                if(one == 1) ans += temp;
                else {
                    ans = Integer.toString(i+1);
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}
