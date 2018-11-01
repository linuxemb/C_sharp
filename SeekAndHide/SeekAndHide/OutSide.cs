using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeekAndHide
{
    class OutSide:Location 
    {
        private bool hot;
        public bool Hot { get { return hot; } }

       public OutSide(string name, bool hot) :base(name)
        {
            this.hot = hot;
        }

        public override string Description
        {
            get
            {
                string NewDescription = base.Description;
                if (hot)
                    NewDescription += "Its very hot.";
                return NewDescription;
            }
        }


    }
}
