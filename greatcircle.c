
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"greatcircle.h"

#define DEGREES_IN_RADIAN 57.29577951
#define MEAN_EARTH_RADIUS_KM 6371
#define KILOMETRES_IN_MILE 1.60934

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
static void validate_degrees(greatcircle* gc);
static void calculate_radians(greatcircle* gc);
static void calculate_central_angle(greatcircle* gc);
static void calculate_distance(greatcircle* gc);

// --------------------------------------------------------
// FUNCTION greatcircle_create
// --------------------------------------------------------
greatcircle* greatcircle_create(char* name1,
                                double latitude1_degrees,
                                double longitude1_degrees,
                                char* name2,
                                double latitude2_degrees,
                                double longitude2_degrees)
{
    greatcircle* gc = malloc(sizeof(greatcircle));

    gc->name1 = malloc(strlen(name1) + 1);
    strcpy(gc->name1, name1);

    gc->name2 = malloc(strlen(name2) + 1);
    strcpy(gc->name2, name2);

    gc->latitude1_degrees = latitude1_degrees;
    gc->longitude1_degrees = longitude1_degrees;

    gc->latitude2_degrees = latitude2_degrees;
    gc->longitude2_degrees = longitude2_degrees;

    return gc;
}

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
void greatcircle_calculate(greatcircle* gc)
{
    validate_degrees(gc);

    if(gc->valid)
    {
        calculate_radians(gc);
        calculate_central_angle(gc);
        calculate_distance(gc);
    }
}

// --------------------------------------------------------
// FUNCTION greatcircle_print
// --------------------------------------------------------
void greatcircle_print(greatcircle* gc)
{
    if(gc->valid)
    {
        printf("%s\n", gc->name1);
        printf("Latitude:  %lf degrees / %lf radians \n", gc->latitude1_degrees, gc->latitude1_radians);
        printf("Longitude: %lf degrees / %lf radians \n", gc->longitude1_degrees, gc->longitude1_radians);

        printf("%s\n", gc->name2);
        printf("Latitude: %lf  degrees / %lf radians\n", gc->latitude2_degrees, gc->latitude2_radians);
        printf("Longitude: %lf degrees / %lf radians\n", gc->longitude2_degrees, gc->longitude2_radians);

        printf("Valid: %s\n", gc->valid ? "Yes" : "No");

        printf("Central Angle %lf radians / %lf degrees\n", gc->central_angle_radians, gc->central_angle_degrees);

        printf("Distance %lf kilometres / %lf miles\n", gc->distance_kilometres, gc->distance_miles);
    }
    else
    {
        printf("Latitude and longitude for %s to %s are invalid\n", gc->name1, gc->name2);
    }

    puts("---------------------------------------------------------------");
}

// --------------------------------------------------------
// FUNCTION greatcircle_free
// --------------------------------------------------------
void greatcircle_free(greatcircle* gc)
{
    free(gc->name1);
    free(gc->name2);
    free(gc);
}

// --------------------------------------------------------
// STATIC FUNCTION validate_degrees
// --------------------------------------------------------
static void validate_degrees(greatcircle* gc)
{
    gc->valid = true;

    if(gc->latitude1_degrees < -90.0 || gc->latitude1_degrees > 90.0)
    {
        gc->valid = false;
    }

    if(gc->longitude1_degrees < -180.0 || gc->longitude1_degrees > 180.0)
    {
        gc->valid = false;
    }

    if(gc->latitude2_degrees < -90.0 || gc->latitude2_degrees > 90.0)
    {
        gc->valid = false;
    }

    if(gc->longitude2_degrees < -180.0 || gc->longitude2_degrees > 180.0)
    {
        gc->valid = false;
    }
}

// --------------------------------------------------------
// STATIC FUNCTION calculate_radians
// --------------------------------------------------------
static void calculate_radians(greatcircle* gc)
{
    gc->latitude1_radians = gc->latitude1_degrees / DEGREES_IN_RADIAN;
    gc->longitude1_radians = gc->longitude1_degrees / DEGREES_IN_RADIAN;

    gc->latitude2_radians = gc->latitude2_degrees / DEGREES_IN_RADIAN;
    gc->longitude2_radians = gc->longitude2_degrees / DEGREES_IN_RADIAN;
}

// --------------------------------------------------------
// STATIC FUNCTION calculate_central_angle
// --------------------------------------------------------
static void calculate_central_angle(greatcircle* gc)
{
    double longitudes_abs_diff;

    if(gc->longitude1_radians > gc->longitude2_radians)
    {
        longitudes_abs_diff = gc->longitude1_radians - gc->longitude2_radians;
    }
    else
    {
        longitudes_abs_diff = gc->longitude2_radians - gc->longitude1_radians;
    }

    gc->central_angle_radians = acos(sin(gc->latitude1_radians)
                                       * sin(gc->latitude2_radians)
                                       + cos(gc->latitude1_radians)
                                       * cos(gc->latitude2_radians)
                                       * cos(longitudes_abs_diff));

    gc->central_angle_degrees = gc->central_angle_radians * DEGREES_IN_RADIAN;
}

// --------------------------------------------------------
// STATIC FUNCTION calculate_distance
// --------------------------------------------------------
static void calculate_distance(greatcircle* gc)
{
    gc->distance_kilometres = MEAN_EARTH_RADIUS_KM * gc->central_angle_radians;

    gc->distance_miles = gc->distance_kilometres / KILOMETRES_IN_MILE;
}
