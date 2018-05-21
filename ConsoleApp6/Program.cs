using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Program
    {


        //====================================
        //Deleget 
        public enum workType
        {
            gotomeetins,
            golf,
            generatereports
        }

        public delegate void WorkPerformedHandler(int hours, workType workType);

        static void Main(string[] args)
        {
            // create call back
            WorkPerformedHandler del1 = new WorkPerformedHandler(workPerformed1);

            WorkPerformedHandler del2 = new WorkPerformedHandler(workPerformed2);
            // del1(5, workType.golf);
            //del2(10, workType.generatereports);

            dowork(del1);
            dowork(del2);
            Console.Read();

        }

        static void dowork(WorkPerformedHandler del)
        {
            // invoke delegate by 
            del(4, workType.gotomeetins);
        }

        
        static void workPerformed1(int hours, workType workType)
        {
            Console.WriteLine("workeperformed 1 called" + hours.ToString());
        }
        static void workPerformed2(int hours, workType workTypez)
        {
            Console.WriteLine("workeperformed 2 called" + hours.ToString());
        }



    }
}
