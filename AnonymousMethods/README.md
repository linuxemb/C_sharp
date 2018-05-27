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




Aonymous Methods *****
*****************************
CurrentSpeed = 30
CurrentSpeed = 50
CurrentSpeed = 70
Eek! Going too fast!  1
Message from Car: 2 ,Careful buddy!  Gonna blow!
CurrentSpeed = 90
Fatal Message from Car: 2, Sorry, this car is dead...
AboutToBlow event was fired 2 times.


