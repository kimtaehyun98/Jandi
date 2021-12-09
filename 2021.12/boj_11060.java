import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import static java.lang.Math.*;

class Pair {
    
    public int fir;
    public int sec;
    
    public Pair(int fir, int sec) {
        this.fir = fir;
        this.sec = sec;
    }
}

public class Main {
    
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        
        // 입력 부분
        int n = input.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++) arr[i] = input.nextInt();
        
        // bfs
        Queue<Pair> q = new LinkedList<>();
        int dis[] = new int[n];
        boolean check[] = new boolean[n];
        Pair p = new Pair(0, arr[0]);
        q.add(p);
        dis[0] = 0; check[0] = true;
        while(!q.isEmpty()){
            Pair now = q.poll();
            for(int i=now.fir + 1; i<=now.fir + now.sec; i++){
                if(i >= n) break;
                if(check[i]) continue;
                dis[i] = dis[now.fir] + 1;
                Pair temp = new Pair(i, arr[i]);
                check[i] = true;
                q.add(temp);
            }
        }
        // 출력 및 종료
        if(check[n-1]){
            System.out.println(dis[n-1]);
        }
        else{
            System.out.println("-1");
        }
    }
}
