using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeekAndHide
{
    abstract class Location
    {
        private string name;
        public string Name
        {
            get { return name; }
        }

        public Location[] Exits;
        public Location(string name)
        {
            this.name = name;
        }
        public virtual string Description
        {
            get
            {
                string description = "You are standing in the " + name + ". you see exits to the following places:";
                for (int i = 0; i < Exits.Length - 1; i++)
                {
                    description += " " + Exits[i].Name;
                    if (i != Exits.Length - 1)
                        description += ",";
                }

                description += ".";
                return description;
            }

        }
    }
}
