#pragma once


#include <stdint.h>
#include <stdbool.h>
#include "BatteryUser.h"

#define colsSocTable	5
#define colsRangeTable  4
#define rowsSocTable   21

const uint16_t TableSOC[rowsSocTable][colsSocTable] =

//soc  -40   -18   25   55
{
{ 0, 3456, 3380, 3300, 2500 },
{ 5, 3457, 3407, 3357, 2557 },
{ 10, 3458, 3446, 3412, 3267 },
{ 15, 3460, 3479, 3438, 3405 },
{ 20, 3462, 3509, 3481, 3431 },
{ 25, 3462, 3533, 3518, 3473 },
{ 30, 3462, 3554, 3547, 3512 },
{ 35, 3477, 3572, 3574, 3542 },
{ 40, 3502, 3588, 3593, 3571 },
{ 45, 3523, 3604, 3608, 3602 },
{ 50, 3545, 3619, 3622, 3618 },
{ 55, 3566, 3637, 3639, 3633 },
{ 60, 3588, 3661, 3658, 3651 },
{ 65, 3614, 3691, 3684, 3675 },
{ 70, 3644, 3728, 3719, 3705 },
{ 75, 3679, 3772, 3777, 3753 },
{ 80, 3720, 3821, 3825, 3812 },
{ 85, 3767, 3869, 3868, 3859 },
{ 90, 3818, 3912, 3913, 3906 },
{ 95, 3871, 3956, 3960, 3952 },
{ 100, 3933, 3904, 4020,3999 }
};
