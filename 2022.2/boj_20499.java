import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        String str = input.next();
        str += '/';
        
        int temp = 0, c = 0;
        int arr[] = new int[3];
        for(int i=0; i<str.length(); i++) {
            if (str.charAt(i) == '/') {
                arr[c++] = temp;
                temp = 0;
            } else {
                temp = temp * 10 + (str.charAt(i) - '0');
            }
        }
        
        if(arr[0] + arr[2] < arr[1] || arr[1] == 0) str = "hasu";
        else str = "gosu";
    
        System.out.println(str);
        
    }
}
