
public class OneAway {
	
	static boolean onewaycheck(String str1,String str2)
	{
		//if differnce is more than one.
		if(Math.abs(str1.length()-str2.length())>1)
		{
			return false;
		}
		
		
		//get the short and long string.
		String s1=str1.length()<str2.length()?str1:str2; //smaller one
		String s2=str1.length()<str2.length()?str2:str1; //bigger one
		
		int index1=0;
		int index2=0;
		char[] chars1 = s1.toCharArray();
		char[] chars2 = s2.toCharArray();
		
		boolean founddiff=false; //to check one diff
		
		while(index1<chars1.length && index2<chars2.length)
		{
			if(chars1[index1]!=chars2[index2])
			{
				//ensure this is the first difference
				if(founddiff)
				{
					return false;
				}
				founddiff=true;
				
				if(chars1.length==chars2.length)  //replace,move shorter pointer
				{
					index1++;
				}
			}
			else {  
				
				index1++;  //if matching move shorter pointer
			}
			index2++;		
		}
		return true;
	}
	

	public static void main(String[] args) {
		System.out.println(onewaycheck("abcd", "abcde"));
		
		

	}

}
