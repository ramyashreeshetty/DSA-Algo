
public class PalindromePermutation {
	
	static boolean check(String str)
	{
		int countOdd=0;
		int[] count=new int[26];
		
		for(char c:str.toCharArray())
		{
			if(c>='a' && c<='z')
			{
				count[c-'a']++;
				if(count[c-'a']%2==1)
				{
					countOdd++;
				}
				else {
					countOdd--;
				}
			}
			
		}
		
		return countOdd<2;
	}

	public static void main(String[] args) {

        boolean ans=check("tact oca");
        
        if(ans)
        {
        	System.out.println("Yes");
        }
        else {
        	System.out.println("No");
        }

	}

}
