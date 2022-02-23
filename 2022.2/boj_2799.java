import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        int m = input.nextInt();
        int n = input.nextInt();
        
        char arr[][] = new char[505][505];
        for(int i=0; i<5*m+1; i++){
            String str = input.next();
            for(int j=0; j<5*n+1; j++){
                arr[i][j] = str.charAt(j);
            }
        }
    
        int s1 = 5*(n-1)+1;
        int s2 = 5*(m-1)+1;
        
        int ans[] = new int[5];
        for(int c=1; c<=s1; c+=5){
            for(int r = 1; r <= s2; r+=5){
                if(arr[r][c] == '*'){
                    int cnt = 1;
                    for(int k=r+1; k<r+4; k++) {
                        if(arr[k][c] == '*') cnt++;
                        else break;
                    }
                    ans[cnt]++;
                }
                else ans[0]++;
            }
        }
        
        for(int i=0; i<5; i++) {
            System.out.print(ans[i]);
            System.out.print(" ");
        }
    }
}
