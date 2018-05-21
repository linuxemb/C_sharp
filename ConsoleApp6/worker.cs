using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    //public delegate int WorkPerformedHandler(int hours, workType workType);
    //public delegate void WorkCompleted();

    class worker
    {
        //public event  WorkPerformedHandler WorkPerformed;  // ------event define
        //                                                 //  public event EventHandler WorkCompleted;  // build in handler  --notify work is done
        //public event EventHandler WorkCompleted;

        public event EventHandler<WorkPerformedEventArgs> WorkPerformed;
        public event EventHandler WorkCompleted;


         public  void dowork(int hours, workType worktype)
        {
            // do work to notify cm work been perforemd
            
            for  (int i =0; i < hours; i++)
            {
                System.Threading.Thread.Sleep(1000); //suspends current th for 1 s
                onWorkPerformed(i + 1, worktype);

            }
            // Raise event
            onWorkCompleted();

        }

        // add seperate mehthod for each event  
        protected virtual void onWorkPerformed(int hours, workType worktype)
        {

            //// way 1 
            //if (WorkPerformed != null)
            //{
            //    WorkPerformed(hours, worktype);
            //}

            Console.WriteLine("Work Performeded");

            //   var  del = WorkPerformed as WorkPerformedHandler;
            var del = WorkPerformed as EventHandler<WorkPerformedEventArgs>;
            if (del != null)
            {
               //  del(hours, worktype);    // Raise event
                del(this, new WorkPerformedEventArgs(hours, worktype));
            }
        }


        protected virtual void onWorkCompleted()
        {//if (WorkCompleted != null)
         //{
         //    WorkCompleted(this, EventArgs.Empty);
         //}
            Console.WriteLine("Work completed");

            var del = WorkCompleted as EventHandler;
            if (del != null)
            {
                del(this, EventArgs.Empty);    // Raise evetn
            }
        }
    }
}
