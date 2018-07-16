OBJ initialization syntax decrease num of keystrokes, replace old sch…

…ool approch

Rectangel r = new Rectangle.cs();
Point p1 = new Point();
p1.X=10;
p1.Y =10;
r.Topleft =p1;====>  by
Create and init a rectangel

Rectangle myRect = new rectagle
{
  TopLeft = new Point { x=10, Y =10},
  BottomRight  = new Point { X =200, Y = 200}
};

TopLeft =

......