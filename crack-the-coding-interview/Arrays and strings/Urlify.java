// Q. Write a method to replace all the spaces in a string with ‘%20’. You may assume that the string has sufficient space at the end to hold the additional characters and that you are given the “true” length of the string.
// Examples: 

// Input: "Mr John Smith", 13
// Output: Mr%20John%20Smith

// Input: "Mr John Smith   ", 13
// Output: Mr%20John%20Smith


public class Urlify {
	
	static char[] replace(char[] str)
	{
		int spacecount=0;
		
		//count the spaces
		for(int i=0;i<str.length;i++)
		{
			if(str[i]==' ')
			{
				spacecount++;
			}
		}
		
		
		//calculate the new length
		int newlen=(str.length+(spacecount*3))-spacecount;
		int j=0;
		
		//create a new char-array
		char newstr[] = new char[newlen];
		
		//replace
		for(int i=0;i<str.length;i++)
		{
			if(str[i]==' ')
			{
				newstr[j]='%';
				newstr[j+1]='2';
				newstr[j+2]='0';
				j=j+3;	
			}
			else {
				newstr[j]=str[i];
				j++;
			}
		}
		
		return newstr;
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String s="Mr John Smith pp is small";
		char[] str=s.toCharArray();
		str=replace(str);	
		
		for(int i=0;i<str.length;i++)
		{
			System.out.print(str[i]);
		}

	}

}
