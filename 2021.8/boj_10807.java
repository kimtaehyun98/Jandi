import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner input = new Scanner(System.in);
		
		int n = input.nextInt();
		
		int [] arr = new int[n];
		
		for(int i=0;i<n;i++){
			arr[i] = input.nextInt();
		}
		
		int x = input.nextInt();
		int ans = 0;
		
		for(int i=0;i<n;i++){
			if(arr[i] == x) ans++;
		}
		
		System.out.println(ans);
	}
}