#include "../../Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 6 || !strncmp(argv[1],"-h",2))
    {
        puts("DrawLineSegment: Prints a line through two given points");
        puts("USAGE: ./DrawLineSegment x x x x");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(1));
    curs_set(0);

    double x1 = atof(argv[1]);
    double y1 = atof(argv[2]);
    double x2 = atof(argv[3]);
    double y2 = atof(argv[4]);
    double theta = atof(argv[5]); //the angle of rotation in degrees

    Pair mid = midPoint(x1,y1,x2,y2);
    Pair rpoint1 = rotateDPoint(mid.x,mid.y,x1,y1,theta);
    Pair rpoint2 = rotateDPoint(mid.x,mid.y,x2,y2,theta);

    //draw the starting line
    drawLSeg(x1,y1,x2,y2); //draw the line
    refresh();			/* Print it on to the real screen */

    //draw the midpoint
    attron(COLOR_PAIR(2));
    drawPair(mid);

    //draw the line rotated about the middle point
    attron(COLOR_PAIR(1));
    drawLSeg(rpoint1.x,rpoint1.y,rpoint2.x,rpoint2.y); //draw the line
    refresh();			/* Print it on to the real screen */

    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

