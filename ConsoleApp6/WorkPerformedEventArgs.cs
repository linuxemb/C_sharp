using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class WorkPerformedEventArgs : EventArgs
    {
        public WorkPerformedEventArgs(int hours, workType worktype)
        {
            Hours = hours;
            WorkType = worktype;
        }

        public int Hours { get; set; }
        public workType WorkType { get; set; }
    }
}
