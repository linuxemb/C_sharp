using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CarDelegateMethodGroupConversion
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***** Method Group Conversion *****\n");
            // note we are not directly allocatin the associated delegate obj, but rather simply specifying a method that matatch
            // the delegate's expected signature.
            Car c1 = new Car();
            // old way of register
            //c1.RegisterWithCarEngine(new Car.CarEngineHandler(CallMeHere));
            
            // Register the simple method name.
           
             c1.RegisterWithCarEngine(CallMeHere);

            Console.WriteLine("***** Speeding up *****");
            for (int i = 0; i < 6; i++)
                c1.Accelerate(20);

            // Unregister the simple method name.
           c1.UnRegisterWithCarEngine(CallMeHere);

            // No more notifications!
            for (int i = 0; i < 6; i++)
                c1.Accelerate(20);

            Console.ReadLine();
        }

        static void CallMeHere(string msg)
        {
            Console.WriteLine("=> Message from Car: {0}", msg);
        }
    }
}
