Read-only fields  ---
cant be change dafter initaila ssignment. 

but unlike a constant , the val assigned to a rad-only field can be determained at runtime and so, can leaglly be assigned with ethe scoope of a ctroor but nowhere else.

when dont know the va until run time, ex need to read a external file to obtain the value, but want to ensure taht the val will not change after that point.

Static read-only fields

unlike a constant filed, read-only not implicity ly statix, so if nned expose from PI from the class level, must explicityly use the "static " keyworkd,

BUT if the val of static read linly is not know until runtime, need ust a static conto 


class myNathclass
{


public static readonly double PI;
static myMathClass()
{
Pi = 3.14}

}

