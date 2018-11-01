using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SeekAndHide
{
    public partial class Form1 : Form
    {

        Location currentLocation;

        RoomWithDoor livingRoom;
        Room diningRoom;
        RoomWithDoor kitchen;

        OutsideWithDoor frontYard;
        OutsideWithDoor backYard;
        OutSide garden;
       // OutSide driveway;

        public Form1()
        {
            InitializeComponent();
            CreateObject();
            MoveToANewLocation(livingRoom);
         }
         private void CreateObject()
        {            
            livingRoom = new RoomWithDoor("Living Room", "an antique carpet",
                       "an oak door with a brass handle");
            diningRoom = new Room ("Dinning room", "a crystal chandelier");
            kitchen = new RoomWithDoor("Kitchen", "stainless steel appliances","a screen door");
                       
            //stairs = new Room("Stairs", "a wooden bannister");
            //hallway = new RoomWithHidingPlace("Upstairs Hallway", "a picture of a dog",
            //          "in the closet");
            //bathroom = new RoomWithHidingPlace("Bathroom", "a sink and a toilet",
            //          "in the shower");
            //masterBedroom = new RoomWithHidingPlace("Master Bedroom", "a large bed",
            //          "under the bed");
            //secondBedroom = new RoomWithHidingPlace("Second Bedroom", "a small bed",
            //          "under the bed");

            frontYard = new OutsideWithDoor("Front Yard", false, "a heavy-looking oak door");
            backYard = new OutsideWithDoor("Back Yard", true, "a screen door");
            garden = new OutSide("Garden", false);
           // driveway = new Outside("Driveway", true);

            diningRoom.Exits = new Location[] { livingRoom, kitchen };
            livingRoom.Exits = new Location[] { diningRoom };
            kitchen.Exits = new Location[] { diningRoom };
            //stairs.Exits = new Location[] { livingRoom, hallway };
            //hallway.Exits = new Location[] { stairs, bathroom, masterBedroom, secondBedroom };
            //bathroom.Exits = new Location[] { hallway };
            //masterBedroom.Exits = new Location[] { hallway };
            //secondBedroom.Exits = new Location[] { hallway };
            frontYard.Exits = new Location[] { backYard, garden };
            backYard.Exits = new Location[] { frontYard, garden };
            garden.Exits = new Location[] { backYard, frontYard };
            //driveway.Exits = new Location[] { backYard, frontYard };

            livingRoom.DoorLocation = frontYard;
            frontYard.DoorLocation = livingRoom;

            kitchen.DoorLocation = backYard;
            backYard.DoorLocation = kitchen;

        }

         private void  MoveToANewLocation(Location newLocation)
        {
            currentLocation = newLocation;
            exits.Items.Clear();
            for(int i =0;i<currentLocation.Exits.Length; i++)
            {
                exits.Items.Add(currentLocation.Exits[i].Name);
                exits.SelectedIndex = 0;
                description.Text = currentLocation.Description;
                if (currentLocation is IHasExteriorDoor)
                    goThroughDoor.Visible = true;
                else
                    goThroughDoor.Visible = false;
              
            }
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void exits_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void goHere_Click(object sender, EventArgs e)
        {
            MoveToANewLocation(currentLocation.Exits[exits.SelectedIndex]);
        }

        private void goThroughDoor_Click(object sender, EventArgs e)
        {
            IHasExteriorDoor hasDoor = currentLocation as IHasExteriorDoor;
            MoveToANewLocation(hasDoor.DoorLocation);
        }
    }

}
