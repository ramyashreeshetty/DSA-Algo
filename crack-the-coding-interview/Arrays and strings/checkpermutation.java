// Write a function to check whether two given strings are Permutation of each other or not. A Permutation of a string is another string that contains same characters, only the order of characters can be different. For example, “abcd” and “dabc” are Permutation of each other.

import java.util.*;
public class checkpermutation {

	static int checkperm(String str1,String str2)
    {
        int n1=str1.length();
        int n2=str2.length();

        if(n1!=n2)
            return 0;
        
        char c1[]=str1.toCharArray();
        char c2[]=str2.toCharArray();

        Arrays.sort(c1);
        Arrays.sort(c2);

        for(int i=0;i<n1;i++)
        {
            if(c1[i]!=c2[i])
            {
                return 0;
            }
        }

        return 1;


    }

    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);
        String s1,s2;
        System.out.print("Enter string1:");
        s1=sc.next();
        System.out.println();
        System.out.print("Enter string2:");
        s2=sc.next();

        sc.close();

        if(checkperm(s1,s2)==1)
        {
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }

    }

}
