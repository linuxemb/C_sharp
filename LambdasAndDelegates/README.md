using delgate to implemmet anomous methods"

relpalce by delgate + signature of evnets handler

worker.WorkPerformed += Worker_WorkPerformed;
            // assign line 26 worker_workPerformed(obj,evt )to here
            worker.WorkPerformed += delegate (object sender, WorkPerformedEventArgs e)
           
Replace  Worker_workPerformed(, ) with anonousname methods after dele[M ]+gate

static void Worker_WorkPerformed(object sender, WorkPerformedEventArgs e)
       {
           Console.WriteLine("Worked: " + e.Hours + " hour(s) doing: " + e.WorkType);
       }  // being used by delegae to anonoums meathod

