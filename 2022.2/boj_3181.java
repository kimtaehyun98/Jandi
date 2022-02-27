import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
    
        String str = input.nextLine();
        str += " ";
        String cmp[] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
        
        String temp = "";
        String ans = "";
        int flag = 0;
        for(int i=0; i<str.length(); i++){
            char c = str.charAt(i);
            if(str.charAt(i) == ' ') {
                if(flag == 0) {
                    ans += temp.charAt(0);
                }
                else {
                    boolean stop = false;
                    for (int k = 0; k < 10; k++) {
                        if (cmp[k].equals(temp)) {
                            stop = true;
                            break;
                        }
                    }
                    if(!stop) ans += temp.charAt(0);
                }
                temp = "";
                flag++;
            }
            else {
                temp += c;
            }
        }
        ans = ans.toUpperCase();
        System.out.println(ans);
    }
}
