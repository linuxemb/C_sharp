using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LambdasAndDelegates
{
    public delegate int BizRuleDelegate(int x, int y);
    class Program
    {
        static void Main(string[] args)
        {
            // lambda intergrate with delegate make code consize
            BizRuleDelegate addDel = (x, y) => x + y;
            BizRuleDelegate multiDel = (x, y) => x * y;
            var data = new ProcessData();
            data.Process(2, 3, addDel);
            data.Process(2, 3, multiDel);

            var worker = new Worker();
            //worker.WorkPerformed += Worker_WorkPerformed;
            // assign line 26 worker_workPerformed(obj,evt )to here
            worker.WorkPerformed += delegate (object sender, WorkPerformedEventArgs e)
            {
                Console.WriteLine("Worked: " + e.Hours + " hour(s) doing: " + e.WorkType);
            };

            // worker.WorkCompleted += Worker_WorkCompleted;
            //  worker.WorkCompleted -= Worker_WorkCompleted;
            worker.WorkCompleted  += delegate(object sender, EventArgs e)
            {
                Console.WriteLine("Work is complete!");
            } ;
            worker.DoWork(8, WorkType.GenerateReports);

            Console.Read();
        }

        //static void Worker_WorkPerformed(object sender, WorkPerformedEventArgs e)
        //{
        //    Console.WriteLine("Worked: " + e.Hours + " hour(s) doing: " + e.WorkType);
        //}  // being used by delegae to anonoums meathod

    //    static void Worker_WorkCompleted(object sender, EventArgs e)
    //    {
    //        Console.WriteLine("Work is complete!");
    //    }
    }
}
