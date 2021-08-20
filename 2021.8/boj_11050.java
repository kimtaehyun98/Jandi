import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
	
		int n = in.nextInt();
		int k = in.nextInt();
		
		System.out.println(solve(n,k));
	}
	
	public static int solve(int n, int k) {
		return factorial(n)/(factorial(n-k)*factorial(k));
	}
		
	public static int factorial(int x) {
		if(x <= 1) return 1;
		else return x * factorial(x - 1);
	}
}