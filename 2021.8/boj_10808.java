import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner input = new Scanner(System.in);
		String s = input.nextLine();
		
		int[] alpha = new int[26];
		
		for(int i = 0; i < s.length(); i++) {
			alpha[s.charAt(i) - 'a']++;
		}
		
		for(int i = 0; i < 26; i++) {
			System.out.print(alpha[i]);
			System.out.print(" ");
		}
	}
}