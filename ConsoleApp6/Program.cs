using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    //====================================
    //Deleget 
    public enum workType
    {
        gotomeetins,
        golf,
        generatereports
    }

    class Program
    {     
        static void Main(string[] args)
        {
            // create call back
            //WorkPerformedHandler del1 = new WorkPerformedHandler(workPerformed1);

            //WorkPerformedHandler del2 = new WorkPerformedHandler(workPerformed2);
            //WorkPerformedHandler del3 = new WorkPerformedHandler(workPerformed3);
            //WorkPerformedHandler del4 = new WorkPerformedHandler(workPerformed4);
            // del1(5, workType.golf);
            //del2(10, workType.generatereports);

            //  del1 += del2;
            //  del1 += del3;
            // del1 += del2 + del3;   // combing
            //  dowork(del1);
            // dowork(del2);

            //int finalHours =  del1(10, workType.generatereports);
            // Console.WriteLine("Total hours" + finalHours.ToString());

            var worker = new worker();
            worker.WorkPerformed += delegate (object sender, WorkPerformedEventArgs e)
            {
                Console.WriteLine("Hours wokred:" + e.Hours + "" + e.WorkType);
            };

            worker.WorkCompleted += delegate (object sender, EventArgs e)
            {
                Console.WriteLine("Worker is done");
            };
            worker.dowork(3, workType.golf);
            worker.dowork(7, workType.gotomeetins);
            worker.dowork(5, workType.generatereports);
            Console.Read();

        }

        //static void dowork(WorkPerformedHandler del)
        //{
        //    // invoke delegate by 
        //    del(4, workType.gotomeetins);
        //}

        
        //static int workPerformed1(int hours, workType workType)
        //{
        //    Console.WriteLine("workeperformed 1 called" + hours.ToString());
        //    return hours + 1;
        //}
        //static int workPerformed2(int hours, workType workTypez)
        //{
        //    Console.WriteLine("workeperformed 2 called" + hours.ToString());
        //    return hours + 2;
        //}
        //static int workPerformed3(int hours, workType workTypez)
        //{
        //    Console.WriteLine("workeperformed 3 called" + hours.ToString());
        //    return hours + 3;
        //}


    }
}
