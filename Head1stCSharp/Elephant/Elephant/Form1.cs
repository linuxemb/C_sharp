using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Elephant
{
    public partial class Form1 : Form
    {
        Elephant lucinda;
        Elephant lloyd;


        public Form1()
        {
            InitializeComponent();
            lucinda = new Elephant() { Name = "Lucinda", EarSize = 33 };
            lloyd = new Elephant() { Name = "LIoyd", EarSize = 40 };
            lloyd.TellMe("Hi", lucinda);
            lucinda.SpeakTo(lloyd, "Hello");

        }

        private void Lucinda_Click(object sender, EventArgs e)
        {
            lucinda.WhoAmI();
        }

        private void LIovd_Click(object sender, EventArgs e)
        {
            lloyd.WhoAmI();
        }

        private void Swap_Click(object sender, EventArgs e)
        {
            Elephant holder;
            holder = lucinda;
            lucinda = lloyd;
            lloyd = holder;
            MessageBox.Show("Object swaped");


        }

        private void button1_Click(object sender, EventArgs e)
        {
            lloyd = lucinda;
            lloyd.EarSize = 4321;
            lloyd.WhoAmI();

        }

        private void bigestEar_Click(object sender, EventArgs e)
        {
            Elephant[] elephants = new Elephant[7];
            elephants[0] = new Elephant() { Name = "Lioyd", EarSize = 40 };
            elephants[1] = new Elephant() { Name = "L", EarSize = 33 };
            elephants[2] = new Elephant() { Name = "Li", EarSize = 25 };
            elephants[3] = new Elephant() { Name = "Lio", EarSize = 43 };
            elephants[4] = new Elephant() { Name = "Lioy", EarSize = 23 };
            elephants[5] = new Elephant() { Name = "Lioyd", EarSize = 240 };
            elephants[6] = new Elephant() { Name = "Lioyda", EarSize = 140 };

            Elephant biggestEars = elephants[0];
            for(int i=0; i<elephants.Length; i++)
            {
                if(elephants[i].EarSize > biggestEars.EarSize)
                {
                    biggestEars = elephants[i];
                }
            }
            MessageBox.Show(biggestEars.EarSize.ToString());
        }

    }
}
