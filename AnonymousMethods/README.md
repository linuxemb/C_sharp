iThe program type no longer define specific static event handlers such as CarAbouttoBlow() or CarExploded(), Rather the unmafamed methods are define dinlint at the time of the caller is handling the event using the += 
psode code


class Program
{
	static void Main(string[] args)
	{
		someType t = new someType();
		t.someEvent += delegate (optionallySpecifiedDelegatedArgs)
		{
		  /* some statements */

		  }
	}		  
	
}
