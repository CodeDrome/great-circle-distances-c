
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<stdlib.h>

#include "greatcircle.h"

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("--------------------------");
    puts("| codedrome.com          |");
    puts("| Great Circle Distances |");
    puts("--------------------------\n");

    greatcircle* gc_london_tokyo = greatcircle_create("London", 51.507222, -0.1275, "Tokyo", 35.683333, 139.683333);
    greatcircle_calculate(gc_london_tokyo);
    greatcircle_print(gc_london_tokyo);
    greatcircle_free(gc_london_tokyo);

    greatcircle* gc_london_new_york = greatcircle_create("London", 51.507222, -0.1275, "New York", 40.7127, -74.0059);
    greatcircle_calculate(gc_london_new_york);
    greatcircle_print(gc_london_new_york);
    greatcircle_free(gc_london_new_york);

    greatcircle* gc_london_new_delhi = greatcircle_create("London", 51.507222, -0.1275, "New Delhi", 28.613889, 77.208889);
    greatcircle_calculate(gc_london_new_delhi);
    greatcircle_print(gc_london_new_delhi);
    greatcircle_free(gc_london_new_delhi);

    greatcircle* gc_london_sydney = greatcircle_create("London", 51.507222, -0.1275, "Sydney", -33.865, 151.209444);
    greatcircle_calculate(gc_london_sydney);
    greatcircle_print(gc_london_sydney);
    greatcircle_free(gc_london_sydney);

    greatcircle* gc_london_cape_town = greatcircle_create("London", 51.507222, -0.1275, "Cape Town", -33.925278, 18.423889);
    greatcircle_calculate(gc_london_cape_town);
    greatcircle_print(gc_london_cape_town);
    greatcircle_free(gc_london_cape_town);

    greatcircle* gc_london_rio_de_janeiro = greatcircle_create("London", 51.507222, -0.1275, "Rio de Janeiro", -22.908333, -43.196389);
    greatcircle_calculate(gc_london_rio_de_janeiro);
    greatcircle_print(gc_london_rio_de_janeiro);
    greatcircle_free(gc_london_rio_de_janeiro);

    greatcircle* gc_london_oblivion = greatcircle_create("London", 51.507222, -0.1275, "Oblivion", 91, 360);
    greatcircle_calculate(gc_london_oblivion);
    greatcircle_print(gc_london_oblivion);
    greatcircle_free(gc_london_oblivion);

    return EXIT_SUCCESS;
}
