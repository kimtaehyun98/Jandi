import java.util.Scanner;

public class Main {
    
    public static int arr[] = new int[5];
    
    public static void qsort(int l, int r) {
        int s=l; int e=r;
        int pivot = arr[(l+r)/2];
        
        if(l >= r) return;
        
        while(s <= e){
            while(arr[s] > pivot) s++;
            while(arr[e] < pivot) e--;
            if(s <= e){
                int temp;
                temp = arr[s];
                arr[s] = arr[e];
                arr[e] = temp;
                s++; e--;
            }
        }
        qsort(l,e);
        qsort(s,r);
    }
    
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        
        int sum = 0;
        for(int i=0; i<5; i++){
            arr[i] = input.nextInt();
            sum += arr[i];
        }
        
        qsort(0, 4);
    
        System.out.println(sum/5);
        System.out.println(arr[2]);
    }
}
