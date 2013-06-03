#include "sin.h"
#include "types.h"

/// Lookup-Table for the sinus-function
const fp1d15_t afp1d15sin_table [] = 
{
    0,
    572,
    1144,
    1715,
    2286,
    2856,
    3425,
    3993,
    4560,
    5126,
    5690,
    6252,
    6813,
    7371,
    7927,
    8481,
    9032,
    9580,
    10126,
    10668,
    11207,
    11743,
    12275,
    12803,
    13328,
    13848,
    14365,
    14876,
    15384,
    15886,
    16384,
    16877,
    17364,
    17847,
    18324,
    18795,
    19261,
    19720,
    20174,
    20622,
    21063,
    21498,
    21926,
    22348,
    22763,
    23170,
    23571,
    23965,
    24351,
    24730,
    25102,
    25466,
    25822,
    26170,
    26510,
    26842,
    27166,
    27482,
    27789,
    28088,
    28378,
    28660,
    28932,
    29197,
    29452,
    29698,
    29935,
    30163,
    30382,
    30592,
    30792,
    30983,
    31164,
    31336,
    31499,
    31651,
    31795,
    31928,
    32052,
    32166,
    32270,
    32365,
    32449,
    32524,
    32588,
    32643,
    32688,
    32723,
    32748,
    32763,
    32767
};

fp1d15_t fp1d15sin (int16_t i16phi)
{
    fp1d15_t fp1d15res; // The result
    int8_t i8quad;      // section of the Sinus graph (0..3)
    int8_t u8mod = 1;   // Factor the Value gets multiplied at the end (1 / -1)

    // Handle negative angles
    if ( i16phi < 0)
    {
        i16phi = -i16phi; // Use the absolute value of the angle
        u8mod = -1;       // But negate the result at the end
    }

    i16phi %= 360;        // Shorten the angle to fit into one period
    i8quad = i16phi / 90; // Split it into four sections (0..3)

    switch ( i8quad)      // Handle each section seperately
    {
        case 0 :          // First section, 0..89 degrees
            fp1d15res = afp1d15sin_table [i16phi];
            break;
        case 1 :          // 90 - 180 degrees
            fp1d15res = afp1d15sin_table [180 - i16phi];
            break;
        case 2 :          // 180 - 270 degrees
            fp1d15res = -afp1d15sin_table [(i16phi -180)];
            break;
        case 3 :          // 270 - 359 degrees
            fp1d15res = -afp1d15sin_table [180 - (i16phi-180)];
            break;
        default:          // This should never be reached...
            return 1;     // Return error code
    }

    if (u8mod != 1)       // We might yet have to negate the result
        fp1d15res = -fp1d15res;                           

    return fp1d15res;
}
/** @} */
