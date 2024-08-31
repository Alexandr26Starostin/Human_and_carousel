#include <TXLib.h>
#include <math.h>

int main()
{
    txCreateWindow (900, 800);
    
    txSetColor (TX_WHITE, 5);

    txLine (450, 600, 400, 700);  //ноги
    txLine (450, 600, 500, 700);

    txLine (450, 600, 450, 500);  //тело

    txCircle (450, 465, 35);      //голова

    txLine (450, 525, 500, 600);  //первая рука

    POINT hat[] = {{430, 430}, {470, 430}, {450, 395}};
    txSetFillColor (TX_YELLOW);
    txSetColor (TX_YELLOW, 5);
    txPolygon (hat, 3);                 // шапка
    txSetColor (TX_WHITE, 5);

    double x = 360;
    double y = 0;

    double vx = 0.1;

    for (;;)
    {
        y = sqrt (8125 - abs (x - 450.0) * abs (x - 450)) + 525;

        txLine (450, 525, x, y);
        txSleep (0.01);

        txSetColor (TX_BLACK, 5);
        txLine (450, 525, x, y);
        txSetColor (TX_WHITE, 5);

        txLine (450, 600, 450, 500);  //повтор тела
        txLine (450, 525, 500, 600);  //повтор 1-ой руки
        txLine (450, 600, 400, 700);  //повтор ног
        txLine (450, 600, 500, 700);

        x += vx;

        if (x < 360 || x > 540)
        {
            vx *= -1;
        }
    }

    return 0;
}