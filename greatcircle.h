
#include<stdbool.h>

// --------------------------------------------------------
// STRUCT greatcircle
// --------------------------------------------------------
typedef struct greatcircle
{
    char* name1;
    double latitude1_degrees;
    double longitude1_degrees;
    double latitude1_radians;
    double longitude1_radians;

    char* name2;
    double latitude2_degrees;
    double longitude2_degrees;
    double latitude2_radians;
    double longitude2_radians;

    double central_angle_radians;
    double central_angle_degrees;

    double distance_kilometres;
    double distance_miles;
    
    bool valid;
} greatcircle;

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
greatcircle* greatcircle_create(char* name1,
                                double latitude1_degrees,
                                double longitude1_degrees,
                                char* name2,
                                double latitude2_degrees,
                                double longitude2_degrees);
void greatcircle_print(greatcircle* gc);
void greatcircle_calculate(greatcircle* gc);
void greatcircle_free(greatcircle* gc);
