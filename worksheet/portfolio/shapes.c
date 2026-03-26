
#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint( float x, float y ) {
    Point new;
    // implementation
    new.x = x;
    new.y = y;

    return new;
}

Line makeLine( Point p1, Point p2 )
{
    // create and return a Line structure
    Line new;
    new.p[0] = p1;
    new.p[1] = p2;

    return new;

}                 

Triangle makeTriangle( Point p1, Point p2, Point p3 )
{

    // create and return a Triangle structure
    Triangle new;
    new.p[0] = p1;
    new.p[1] = p2;
    new.p[2] = p3;

    return new;
}


/*
  Structure calculation functions (requires <math.h>)
*/

float lineLength( Line l )
{
    // calculate the length of a Line 

    float length = sqrt(pow(l.p[1].x - l.p[0].x, 2) + pow(l.p[1].y - l.p[0].y, 2));
    return length;
}        

float triangleArea( Triangle t )
{
    // calculate the area of a Triangle

    Point midpoint;
    midpoint.x = (t.p[0].x + t.p[1].x)/2;
    midpoint.y = (t.p[0].y + t.p[1].y)/2;

    Line breadthCoord;
    breadthCoord.p[0].x = t.p[0].x;
    breadthCoord.p[1].x = t.p[1].x;
    breadthCoord.p[0].y = t.p[0].y;
    breadthCoord.p[1].y = t.p[1].y;

    Line heightCoord;
    heightCoord.p[0].x = midpoint.x;
    heightCoord.p[1].x = t.p[2].x;
    heightCoord.p[0].y = midpoint.y;
    heightCoord.p[1].y = t.p[2].y;

    float breadth = lineLength(breadthCoord);

    float height = lineLength(heightCoord);

    float area = 1/2*(breadth)*(height);
}

/*
  Structure comparison functions (requires <stdbool.h>)

  Note: 
  * to compare 2 points you should not test float values for equality
  * test if they are "close enough"
  * eg. float values are accurate to 8 d.p.
  * abs(lineLength(p1,p2))<1.0e-6 would be sufficient to say p1 and p2 are the same point 
*/

bool samePoint( Point p1, Point p2 )
{
    
    // return true only if the point is the same location
    Line comparePoints;
    comparePoints.p[0].x = p1.x;
    comparePoints.p[1].x = p2.x;
    comparePoints.p[0].y = p1.y;
    comparePoints.p[1].y = p2.y;


    if (abs(lineLength(comparePoints))<1.0e-6)
    {
        return true;
    }

    return false;

}

        
bool pointInLine( Point p, Line l)
{
    // return true only if the point is one of the line endpoints

    bool sameFirstPoint = samePoint(p, l.p[0]);
    bool sameSecondPoint = samePoint(p, l.p[1]);

    if (sameFirstPoint) or (sameSecondPoint)
    {
        return true;
    }

    return false;

}
    
bool pointInTriangle( Point p, Triangle t )
{
    // return true only if the point is one of the triangle vertices

    bool sameFirstPoint = samePoint(p, t.p[0]);
    bool sameSecondPoint = samePoint(p, t.p[1]);
    bool sameThirdPoint = samePoint(p, t.p[2]);

    if (sameFirstPoint) or (sameSecondPoint) or (sameThirdPoint)
    {
        return true;
    }

    return false;
}
  


// complete other functions below
// - start with stubs as above
// - compile regularly to test syntax
// - test functions by calling them from main()
