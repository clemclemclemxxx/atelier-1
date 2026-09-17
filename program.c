#include <stdio.h>

int main(void) {
    const char *speed_unit = "km/h";
    const char *alt_unit = "m";

    int speed = 128;
    int altitude = 3450;
    int heading = 247;
    int bank = 12;

    int speed_low = speed - 20;
    int speed_high = speed + 20;
    int altitude_low = altitude - 150;
    int altitude_high = altitude + 150;
       int speed_upper = speed - 10;
       int speed_lower = speed + 10;
       int altitude_upper = altitude + 50;
       int altitude_lower = altitude - 50;

    printf("     ANEMOMETRE                 HORIZON                    ALTIMETRE\n");
    printf("+-----------+   +---------------------------------+   +-----------+\n");
    printf("|%4d %s   |   |               %4d                |   |%7d %s |\n",
           speed_low, speed_unit, bank, altitude_high, alt_unit);
    printf("|           |   |               .                 |   |           |\n");
    printf("|%4d %s   |   |              %4d                |   |%7d %s |\n",
           speed_upper, speed_unit, bank / 2, altitude_upper, alt_unit);
    printf("|           |   |               .                 |   |           |\n");
    printf("|>[ %03d ]  |   |     <----------X---------->     |   |[ %04d ]  |\n",
           speed, altitude);
    printf("|           |   |               .                 |   |           |\n");
    printf("|%4d %s   |   |             %4d                |   |%7d %s |\n",
           speed_lower, speed_unit, -bank / 2, altitude_lower, alt_unit);
    printf("|           |   |               .                 |   |           |\n");
    printf("|%4d %s   |   |              %4d                |   |%7d %s |\n",
           speed_high, speed_unit, -bank, altitude_low, alt_unit);
    printf("+-----------+   +---------------------------------+   +-----------+\n");
    printf("    %s                                                  %s\n",
           speed_unit, alt_unit);

    printf("\n");
    printf("                          CAP\n");
    printf("   NW      N      NE      E      SE      S      SW      W\n");
    printf("   .       |       .       .       .       .       .       .\n");
       printf("    \\       |       |       |       |       |       |       |\n");
    printf("           [ %03d deg ]\n", heading);

    return 0;
}
