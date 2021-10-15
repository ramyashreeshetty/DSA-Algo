//This will work for two given strings(understood the question wrong oopsss)


import java.util.Arrays;
import java.util.Scanner;

public class TwoPalPerm {
	
	static int palindrome(String s)
	{
		int n=s.length(),flag=0;
		char[] s1=s.toCharArray();
		
		for(int i=0;i<n/2;i++)
		{
			if(s1[i]!=s1[n-1-i])
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0)
		{
			return 1;
		}
		else {
			return 0;
		}
		
	}
	
	static int checkperm(String str1,String str2)
    {
        int n1=str1.length();
        int n2=str2.length();

        if(n1!=n2)
            return 0;
        
        char c1[]=str1.toCharArray();
        char c2[]=str2.toCharArray();

        
        //SORT THEM
        Arrays.sort(c1);
        Arrays.sort(c2);
        
        
        
        //CHECK IF EQUAL
        for(int i=0;i<n1;i++)
        {
            if(c1[i]!=c2[i])
            {
                return 0;
            }
        }

        return 1;
    }

	public static void main(String[] args) {
		
		Scanner s =new Scanner(System.in);
        String s1,s2;
        System.out.print("Enter string1:");
        s1=s.next();
        System.out.println();
        System.out.print("Enter string2:");
        s2=s.next();

        s.close();
        
        int v1=palindrome(s1);
        int v2=palindrome(s2);

        if(v1==1 && v2==1)
        {
        	if(checkperm(s1,s2)==1)
            {
                System.out.println("Yes");
            }
            else{
                System.out.println("No");
            }
        }
        else{
            System.out.println("No");
        }

	}

}
