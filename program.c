#include <stdio.h>

int main(void) {
    const char *speed_unit = "km/h";
    const char *altitude_unit = "ft";
    const char *angle_unit = "deg";

    int speed = 245;
    int altitude = 3200;
    int heading = 235;
    int pitch = 5;
    int bank = -12;

    int speed_position = 3 + speed * 18 / 300;
    int altitude_position = 59 + (altitude - 2000) * 15 / 2000;
    int bank_position = 26 + (bank + 20) * 26 / 40;

    int speed_mark_0 = 0;
    int speed_mark_1 = 100;
    int speed_mark_2 = 200;
    int speed_mark_3 = 300;
    int altitude_mark_0 = 2000;
    int altitude_mark_1 = 3000;
    int altitude_mark_2 = 4000;
    int pitch_mark_high = 10;
    int pitch_mark_mid = 5;
    int pitch_mark_low = -5;
    int pitch_mark_bottom = -10;
    int bank_mark_left = 20;
    int bank_mark_mid = 10;
    int bank_mark_center = 0;
    int bank_mark_right = 20;

    char pitch_plus_10[3] = " ";
    char pitch_plus_5[3] = " ";
    char pitch_zero[3] = " ";
    char pitch_minus_5[3] = " ";
    char pitch_minus_10[3] = " ";

    if (pitch >= 8) {
        pitch_plus_10[0] = '-';
        pitch_plus_10[1] = '>';
    } else if (pitch >= 3) {
        pitch_plus_5[0] = '-';
        pitch_plus_5[1] = '>';
    } else if (pitch > -3) {
        pitch_zero[0] = '-';
        pitch_zero[1] = '>';
    } else if (pitch > -8) {
        pitch_minus_5[0] = '-';
        pitch_minus_5[1] = '>';
    } else {
        pitch_minus_10[0] = '-';
        pitch_minus_10[1] = '>';
    }

    char cardinal[3];
    if (heading >= 338 || heading < 23) {
        cardinal[0] = 'N';
        cardinal[1] = '\0';
    } else if (heading < 68) {
        cardinal[0] = 'N';
        cardinal[1] = 'E';
        cardinal[2] = '\0';
    } else if (heading < 113) {
        cardinal[0] = 'E';
        cardinal[1] = '\0';
    } else if (heading < 158) {
        cardinal[0] = 'S';
        cardinal[1] = 'E';
        cardinal[2] = '\0';
    } else if (heading < 203) {
        cardinal[0] = 'S';
        cardinal[1] = '\0';
    } else if (heading < 248) {
        cardinal[0] = 'S';
        cardinal[1] = 'W';
        cardinal[2] = '\0';
    } else if (heading < 293) {
        cardinal[0] = 'W';
        cardinal[1] = '\0';
    } else {
        cardinal[0] = 'N';
        cardinal[1] = 'W';
        cardinal[2] = '\0';
    }

    printf(" ANEMOMETER        HORIZON ARTIFICIAL        ALTIMETER\n");
    printf("+----------+   +----------------------+   +----------+\n");
        printf("|          |   | %s %2d -------------- |          |\n",
            pitch_plus_10, pitch_mark_high);
        printf("| %3d %s |   | %s %2d -------------- | %4d %s |\n",
            speed, speed_unit, pitch_plus_5, pitch_mark_mid,
            altitude, altitude_unit);
    printf("|          |   | %s----[ + ]----     |          |\n", pitch_zero);
        printf("|          |   | %s %2d -------------- |          |\n",
            pitch_minus_5, pitch_mark_low);
        printf("+----------+   | %s%3d -------------- |   +----------+\n",
            pitch_minus_10, pitch_mark_bottom);
        printf(" %d %d %d %d                         %d %d %d\n",
            speed_mark_0, speed_mark_1, speed_mark_2, speed_mark_3,
            altitude_mark_0, altitude_mark_1, altitude_mark_2);
    printf(" |....|....|....|....|                 |....|....|\n");
    printf("%*c%*c\n", speed_position + 1, '^',
           altitude_position - speed_position, '^');
    printf("\n");
        printf(" L %d %d %d %d %d R\n", bank_mark_left, bank_mark_mid,
            bank_mark_center, bank_mark_mid, bank_mark_right);
    printf(" |...|...|...|...|...|...|\n");
    printf("%*c\n", bank_position + 1, '^');
    printf(" VIRAGE : %3d %s\n", bank, angle_unit);
    printf("\n");
    printf(" ----------------------\n");
    printf(" |         N          |\n");
    printf(" |    NW       NE     |\n");
    printf(" | W          X     E |\n");
    printf(" |    SW       SE     |\n");
    printf(" |         S          |\n");
    printf(" ----------------------\n");
    printf(" CAP : %3d %s (%s)\n", heading, angle_unit, cardinal);

    return 0;
}
