using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DinnerParty_first_version
{
    public partial class Form1 : Form
    {
        DinnerParty dinnerParty;
        BirthdayParty birthdayParty;
        public Form1()
        {
            InitializeComponent();
            dinnerParty = new DinnerParty((int)numericUpDown1.Value, healthyBox.Checked,
                                  fancyBox.Checked) ;
            birthdayParty = new BirthdayParty((int)numericUpDown2.Value, fancyBirthday.Checked, cakeWriting.Text);
            DisplayDinnerPartyCost();
        }

        private void fancyBox_CheckedChanged(object sender, EventArgs e)
        {
            dinnerParty.FancyDecorations = fancyBox.Checked;
            DisplayDinnerPartyCost();
        }

        private void healthyBox_CheckedChanged(object sender, EventArgs e)
        {
            dinnerParty.HealthyOption = healthyBox.Checked;
            DisplayDinnerPartyCost();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {            
            dinnerParty.NumberOfPeople = ((int)numericUpDown1.Value); 
            DisplayDinnerPartyCost();
        }

        private void DisplayDinnerPartyCost()
        {
            decimal Cost = dinnerParty.Cost;
            costLabel.Text = Cost.ToString("c");
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {
            DisplayBirthdayPartyCost();
        }

        private void NumberOfPerson_Click(object sender, EventArgs e)
        {


       
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            birthdayParty.NumberofPeople = (int)numericUpDown2.Value;

            DisplayBirthdayPartyCost();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            DisplayBirthdayPartyCost();
        }

        private void DisplayBirthdayPartyCost()
        {
            decimal Costnum = birthdayParty.CalculateCost();
           // costLabel.Text = Cost.ToString("c");
           Cost.Text = Costnum.ToString("c");
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            birthdayParty.CalculateCostDecorations( fancyBirthday.Checked);
            DisplayBirthdayPartyCost();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void cakeWriting_TextChanged(object sender, EventArgs e)
        {
            birthdayParty.CakeWriting = cakeWriting.Text;
            DisplayBirthdayPartyCost();
        }
    }
}
