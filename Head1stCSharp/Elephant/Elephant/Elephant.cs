using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Elephant
{
    class Elephant
    {
        public int EarSize;
        public String Name;

        public void WhoAmI()
        {
            MessageBox.Show("My name is " + EarSize + "inch tail.", Name + "says...");

        }

        public void TellMe(String message, Elephant whoSaidIt)
        {
            MessageBox.Show(whoSaidIt.Name + "says:" + message);
        }

        public void SpeakTo(Elephant talkto, string message)
        {
            talkto.TellMe(message, this);
        }
    }
}
