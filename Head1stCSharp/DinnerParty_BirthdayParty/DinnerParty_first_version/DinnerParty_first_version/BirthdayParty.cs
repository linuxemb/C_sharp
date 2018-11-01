using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace DinnerParty_first_version
{
    class BirthdayParty
    {
       
        public decimal costOfDecorations =0;
        private bool fancyDecorations;
        private  string cakeWriting;
        public int CakeSize;
        private int numOfPeople;
        private const decimal costofFoodPerPerson = 30.4M;
        public BirthdayParty (int numberofperson, bool fancy, string  cakeWriting)

        {
            this.numOfPeople = numberofperson;
            this.fancyDecorations = fancy;
            CalculateCakeSize();
            this.cakeWriting = cakeWriting;
            CalculateCostDecorations(fancyDecorations);
        }
        public void CalculateCostDecorations(bool fancy)
        {
            fancyDecorations = fancy; // save for for use 
            if (fancy)
                costOfDecorations = NumberofPeople * 15.0M + 50M;
            else
                costOfDecorations = NumberofPeople * 7.5M + 30M;

        }
        public decimal CalculateCost()
        {
            decimal TotalCost= costOfDecorations + costofFoodPerPerson * NumberofPeople;
            decimal CakeCost;
            if (CakeSize == 8)
                CakeCost = 40M + CakeWriting.Length * .25M;
            else
                CakeCost = 75M + CakeWriting.Length * .25M;
            return TotalCost;
        }

        private void CalculateCakeSize()
        {
            if (NumberofPeople <= 4)
                CakeSize = 8;
            else CakeSize = 16;
        }

        public string CakeWriting
        {


            get { return this.cakeWriting; }
            set
            {
                int maxLength;
                if (CakeSize ==8)
                {
                    maxLength = 16;
                }
                else maxLength = 40;
                if (value.Length > maxLength)
                {
                    MessageBox.Show("Too many leter for a" + CakeSize + "inch cake");

                    this.cakeWriting = cakeWriting.Substring(0, maxLength);

                }
                else
                    this.cakeWriting = value;
            }
        }

        private int numberOfPeople;
        public int NumberofPeople
        {
            get { return numberOfPeople; }
            set
            {
                numberOfPeople = value;
                CalculateCostDecorations(fancyDecorations);
                CalculateCakeSize();
                CakeWriting = cakeWriting;


            }
        }
      

    }
}
