#include <iomanip>
#include <iostream>
#include <cmath>
#include "Shapes.h"
#include <assert.h>
using namespace std;


string colorList[9] = {"BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE", "INVALID"};

//----Constructor--
Shape::Shape(Color c) { pColor = c; }

Shape::~Shape() { }

//----Getter-------
Color Shape::color() const { return pColor; }

//----Setter-------
void Shape::color(Color c) { pColor = c; }

//----ColorAtPoint-------------
Color Shape::colorAtPoint(Shape** list, int size, double x, double y)
{
	
	for(int i = 0; i < size; i++)
	{

		if(list[i]->inside(x,y))
		{
			return list[i]->color();
		}
	}
	return INVALID;
	
}

double Shape::thickness()
{
	return area()/perimeter();
	
}


//------Constructor-----------------
Box::Box(Color c, double l, double t, double r, double b) : Shape(c)
{
	pLeft = l;
	pTop = t;
	pRight = r;
	pBottom = b;
	
}


//-------Getters---------------------
double Box::left() const { return pLeft; } 
double Box::right() const { return pRight; }
double Box::top() const { return pTop; }
double Box::bottom() const { return pBottom; }

//-------Setters---------------------
void Box::left( double l ) { pLeft = l; }
void Box::right( double r ) { pRight = r; }
void Box::top( double t ) { pTop = t; }
void Box::bottom( double b ) { pBottom = b; }

//----BoxArea------------------------
double Box::area() const
{
	return (pTop-pBottom)*(pRight-pLeft);
	
}

//----BoxPerimeter-------------------
double Box::perimeter() const
{
	return ((pRight-pLeft) *2) + ((pTop-pBottom) *2);
	
}

//----BoxMove------------------------
void Box::move(double x, double y)
{ 
	pLeft += x;
	pRight += x;
	pBottom += y;
	pTop += y;

}

//----BoxRender----------------------
void Box::render(ostream& os) const
{
	os << "Box(" << colorList[color()] << "," << left() << "," << top() << "," << right() << "," << bottom() << ")";

}

//----BoxInside----------------------
bool Box::inside(double x, double y) const
{
	return((pLeft < x && x < pRight) && (pBottom < y && y < pTop));
	
}

//------Constructor-----------------
RoundBox::RoundBox(Color c, double l, double t, double r, double b, double radius) : Shape(c)
{
	pLeft = l;
	pTop = t;
	pRight = r;
	pBottom = b;
	pRadius = radius;
	
}

//-------Getters---------------------
double RoundBox::left() const { return pLeft; } 
double RoundBox::right() const { return pRight; }
double RoundBox::top() const { return pTop; }
double RoundBox::bottom() const { return pBottom; }
double RoundBox::radius() const { return pRadius; }

//-------Setters-------------------------
void RoundBox::left( double l ) { pLeft = l; }
void RoundBox::right( double r ) { pRight = r; }
void RoundBox::top( double t ) { pTop = t; }
void RoundBox::bottom( double b ) { pBottom = b; }
void RoundBox::radius( double radius ) { pRadius = radius; }

//----RoundBoxArea------------------------
double RoundBox::area() const
{
	Circle c(GREEN, 0, 0, pRadius);
	return (((pTop-pBottom)*(pRight-pLeft))) - (4*(pRadius*pRadius) - (c.area()));
	
}

//----RoundBoxPerimeter-------------------
double RoundBox::perimeter() const
{
	Box b(GREEN, pLeft, pTop, pRight, pBottom);
	Circle c(GREEN, 0, 0, pRadius);
	
	return(b.perimeter() + c.perimeter() - (pRadius*8));
	
}

//----RoundBoxMove------------------------
void RoundBox::move(double x, double y)
{ 
	pLeft += x;
	pRight += x;
	pBottom += y;
	pTop += y;

}

//----RoundBoxRender----------------------
void RoundBox::render(ostream& os) const
{
	os << "RoundBox(" << colorList[color()] << "," << left() << "," << top() << "," << right() << "," << bottom() << "," << radius() << ")";
	
}

//----RoundBoxInside----------------------
bool RoundBox::inside(double x, double y) const
{
	//create 2 boxes and 4 circles that make up the roundedBox
	Box bTall(GREEN, pLeft + pRadius, pTop, pRight - pRadius, pBottom);
	Box bLong(GREEN, pLeft, pTop - pRadius, pRight, pBottom + pRadius);
	
	Circle topLeft(GREEN, pLeft, pTop, pRadius);
	Circle topRight(GREEN, pRight, pTop, pRadius);
	Circle bottomRight(GREEN, pRight, pBottom, pRadius);
	Circle bottomLeft(GREEN, pLeft, pBottom, pRadius);
	
	//put everything into an array of shapes and use inside() to find if the point is inside
	//if found in any of the shapes then return true
	
	Shape* ar[6];
	
	ar[0] = &bTall; 
	ar[1] = &bLong;       
	ar[2] = &topLeft;    
	ar[3] = &topRight;
    ar[4] = &bottomRight;
	ar[5] = &bottomLeft;  
	
	for(int i = 0; i < 6; i++)
	{
		if(ar[i]->inside(x,y))
			return true;
	}
	return false;

}

//------Constructor------------------
Circle::Circle (Color c, double center_X, double center_Y, double radiusOfCircle) : Shape(c)
{
	pX = center_X;
	pY = center_Y;
	pRadius = radiusOfCircle;
	
}

//-------Getters---------------------
double Circle::centerX() const { return pX; }
double Circle::centerY() const { return pY; }
double Circle::radius() const { return pRadius; }

//-------Setters---------------------
void Circle::centerX(double center_X) { pX = center_X; }
void Circle::centerY(double center_Y) { pY = center_Y; }
void Circle::radius(double radiusOfCircle) { pRadius = radiusOfCircle; }

//----CircleArea---------------------
double Circle::area() const
{
	return M_PI*pRadius*pRadius;
	
}

//----CirclePerimeter----------------
double Circle::perimeter() const
{
	return 2*M_PI*pRadius;
	
}

//----CircleMove---------------------
void Circle::move(double x, double y)
{ 
		pX += x;
		pY += y;

}

//----CircleRender-------------------
void Circle::render(ostream& os) const
{
	os << "Circle(" << colorList[color()] << ","<< centerX() << "," << centerY() << "," << radius() << ")";

}

//----CircleInside-------------------
bool Circle::inside(double x, double y) const
{
	return sqrt(( x - pX )*( x - pX ) + ( y - pY )*( y - pY )) < pRadius;
	
}

//------Constructor------------------
Triangle::Triangle(Color c, double x1, double y1, double x2, double y2, double x3, double y3) : Shape(c)
{
	pX1 = x1; pY1 = y1;
	pX2 = x2; pY2 = y2;
	pX3 = x3; pY3 = y3;

}

//------Getters----------------------
double Triangle::cornerX1() const { return pX1; }	
double Triangle::cornerY1() const { return pY1; }	
		
double Triangle::cornerX2() const { return pX2; }	
double Triangle::cornerY2() const { return pY2; }	
		
double Triangle::cornerX3() const { return pX3; }	
double Triangle::cornerY3() const { return pY3; }	


//-------Setters---------------------
void Triangle::cornerX1(double X_1) { pX1 = X_1; }	
void Triangle::cornerY1(double Y_1) { pY1 = Y_1; }	
		
void Triangle::cornerX2(double X_2) { pX2 = X_2; }	
void Triangle::cornerY2(double Y_2) { pY2 = Y_2; }	
		
void Triangle::cornerX3(double X_3) { pX3 = X_3; }	
void Triangle::cornerY3(double Y_3) { pY3 = Y_3; }	


//----TriangleArea-------------------
double Triangle::area() const
{		
	double side = perimeter()/2;
	
	double s1 = sqrt((pX2-pX1)*(pX2-pX1)+(pY2-pY1)*(pY2-pY1));
	double s2 = sqrt((pX3-pX2)*(pX3-pX2)+(pY3-pY2)*(pY3-pY2));
	double s3 = sqrt((pX1-pX3)*(pX1-pX3)+(pY1-pY3)*(pY1-pY3));
	
	double area = sqrt(side*(side-s1)*(side-s2)*(side-s3));
	return area;
	
}

//----TrianglePerimeter--------------
double Triangle::perimeter() const
{	
	//distance forumla 3 times then add the sides.
	double side1 = sqrt(((pX1 - pX2) * (pX1 - pX2)) + ((pY1 - pY2) * (pY1 - pY2)));
	double side2 = sqrt(((pX2 - pX3) * (pX2 - pX3)) + ((pY2 - pY3) * (pY2 - pY3)));
	double side3 = sqrt(((pX3 - pX1) * (pX3 - pX1)) + ((pY3 - pY1) * (pY3 - pY1)));
	
	return side1 + side2 + side3;
	
}

//----TriangleMove-------------------
void Triangle::move(double x, double y)
{ 
	pX1 += x; pY1+= y;
	pX2 += x; pY2+= y;
	pX3 += x; pY3+= y;

}

//----TriangleRender-----------------
void Triangle::render(ostream& os) const
{
	os << "Triangle(" << colorList[color()]
		<< "," << cornerX1() << "," << cornerY1()
		<< "," << cornerX2() << "," << cornerY2()
		<< "," << cornerX3() << "," << cornerY3() << ")";

}

//----TriangleInside-----------------
bool Triangle::inside(double x, double y) const
{

		Triangle t1(GREEN, x, y, pX1, pY1, pX2, pY2);
		Triangle t2(GREEN, x, y, pX2, pY2, pX3, pY3);
		Triangle t3(GREEN, x, y, pX1, pY1, pX3, pY3);
		
		double pointArea = t1.area() + t2.area() + t3.area();
		return(pointArea <= area());
		
}

//------Constructor------------------
Polygon::Polygon(Color c, double* pts, int size) : Shape(c)
{
	pSize = size;	
	corners = new double[size*2];
	for(int i = 0; i < size*2; i++)
	{
		corners[i] = pts[i];
	}	
}

//------Destructor--------------------
Polygon::~Polygon() 
{
	delete [] corners;
	
}

//------Getters----------------------
int Polygon::points() const { return pSize; }

double Polygon::vertexX(int index) const
{ 
	return corners[index*2];
	
}

double Polygon::vertexY(int index) const
{ 
	return corners[index*2+1];
	
}

//-------Setters---------------------
void Polygon::vertexX(int index, double x)
{
	corners[index*2] = x;
	
}

void Polygon::vertexY(int index, double y)
{
	corners[index*2+1] = y;
	
}


//----PolygonArea---------------------
double Polygon::area() const
{ 
	double almostArea = 0;
	double X1, X2, Y1, Y2;
	
	for(int i = 0;  i < points()-1;	i++)
	{
		X1 = vertexX(i);   Y1 = vertexY(i);
		X2 = vertexX(i+1); Y2 = vertexY(i+1);

		almostArea += (X1 * Y2) - (X2 * Y1);
	}
	
	//last segment
	int getLastPoint = points() - 1;
	
	//   "last"  vertices set to x1 and y1 
	X1 = vertexX(getLastPoint); Y1 = vertexY(getLastPoint);
	X2 = vertexX(0);            Y2 = vertexY(0);
	//^^ "first" vertices set to x2 and y2^^
	almostArea += (X1 * Y2) - (X2 * Y1);
	
	//Make area always positive
	if(almostArea < 0)
		almostArea *= -1;
		
	return .5 * almostArea;
	
}

//----PolygonPerimeter----------------
double Polygon::perimeter() const
{ 
	double total = 0;
	double side = 0;
	//use the amount of vertex' to see how many times the function needs to use distance forumla
	//gets the coords each time 
	for(int i = 0; i < pSize-1; i++)
	{
		//getting x1 y1 and x2 y2 which changes each iteration to the next segment
		double X1 = vertexX(i);   double Y1 = vertexY(i);
		double X2 = vertexX(i+1); double Y2 = vertexY(i+1);
		
		//distance formula
		side = sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
		total += side;
		//catch if it is a normal segment of the last segment that uses [0] and [1]
	}	
	
	//last segment
	double X1 = vertexX(pSize-1);   double Y1 = vertexY(pSize-1);
	double X2 = vertexX(0);         double Y2 = vertexY(0);
	
	side = sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
	
	return total+side;
}

//----PolygonMove--------------------
void Polygon::move(double x, double y)
{ 
	//gets the index i, and grabs whats in the index then adds x to it
	for(int i = 0; i < points()*2; i++)
	{
		if(i%2==0)
			corners[i]+=x;
		else
			corners[i]+=y;
	}

}

//----PolygonRender-------------------
void Polygon::render(ostream& os) const
{ 
	os << "Polygon(" << colorList[color()] << "," << points();
	
	for(int i = 0; i < points()*2; i++)
	{
		os << ",";
	
		os << corners[i];
	}
	os << ")";
	
}

//----PolygonInside-------------------	
bool Polygon::inside(double x, double y) const
{
	double i, j;
	bool c = false;
	for (i = 0, j = pSize-1; i < pSize; j = i++)
	{
		if (((vertexY(i) > y) != (vertexY(j) > y)) && (x < (vertexX(j) - vertexX(i)) * (y - vertexY(i)) / (vertexY(j) - vertexY(i)) + vertexX(i)))
			c = !c;
	}
	return c;
	
}


//-------Constructor-----------------
Line::Line(Color c, double x1, double y1, double x2, double y2) : Shape(c)
{
	pX1 = x1;   pY1 = y1;
	pX2 = x2; 	pY2 = y2;

}

//-------Getters---------------------
double Line::end1X() const { return pX1; } 
double Line::end1Y() const { return pY1; }
double Line::end2X() const { return pX2; }
double Line::end2Y() const { return pY2; }

//-------Setters---------------------
void Line::end1X( double x1 ) { pX1 = x1; } 
void Line::end1Y( double y1 ) { pY1 = y1; }
void Line::end2X( double x2 ) { pX2 = x2; }
void Line::end2Y( double y2 ) { pY2 = y2; }

//----LineArea------------------------
double Line::area() const
{
	return 0;
	
}

//----LinePerimeter-------------------
double Line::perimeter() const
{
	return sqrt(((pX2 - pX1) * (pX2 - pX1)) + ((pY2 - pY1) * (pY2 - pY1)));
	
}

//----LineMove------------------------
void Line::move(double x, double y)
{	
	//moves both sets of points x and y distance
	pX1 += x;  pY1 += y;
	
	pX2 += x;  pY2 += y;
	
}

//----LineRender----------------------
void Line::render(ostream& os) const
{
	os << "Line(" << colorList[color()] << "," << end1X() << "," << end1Y() << "," << end2X() << "," << end2Y() << ")";

}

//----LineInside----------------------
bool Line::inside(double midX, double midY) const
{
	double total     = sqrt(((pX2  - pX1)  * (pX2  - pX1))  + ((pY2  - pY1)  * (pY2  - pY1)));
	double lengthOne = sqrt(((midX - pX1)  * (midX - pX1))  + ((midY - pY1)  * (midY - pY1)));
	double lengthTwo = sqrt(((pX2 - midX)  * (pX2 - midX))  + ((pY2 - midY)  * (pY2 - midY)));
	
	//if the distance between p1, mid + mid, p2 is == to p1, p2 then the point is on the line
	//if anything else the point is not on the line
	return(total == lengthOne + lengthTwo);

}


//----GroupConstructor-------------------
Group::Group(Color c, int size, Shape** list) : Shape(c)
{
	//make a Shape pointer and change all colors inside of the group
	pSize = size;
	shapesPtr = list;
	
	for(int i = 0; i < pSize; i++)
	{
		shapesPtr[i]->color(c);	
	}
	
}

//-------Getter------------------------
Shape* Group::shape(int N) const { return shapesPtr[N]; } 

Group::~Group()
{	
	//destroy everything in array when it falls out of scope
	for(int i = 0; i < pSize; i++)
	{
		delete shapesPtr[i];
		
	}
	
}

//----GroupShapes----------------------
void Group::shapes(int size, Shape** list)
{
	//delete eveything in the first array //not changing size of the array just chaning the size variable to the size of the new array 
	for(int i = 0; i < pSize; i++)
	{
		delete shapesPtr[i];
		
	}
	
	//set size equal and makes old array point to new arry
	pSize = size;
	shapesPtr = list;
	
}

//----Groupshapes----------------------
int Group::shapes() const
{
	//return size of group
	return pSize;
	
}

//-------Setters---------------------
void Group::color(Color c)
{
	//scope in color(c) from shape to reset groups color
	Shape::color(c);
	
	for(int i = 0; i < pSize; i++)
	{
		//set all the shapes color
		shapesPtr[i]->color(c);	
	}
	
}

//----GroupArea------------------------
double Group::area() const
{
	//total up all the shapes area
	double totalGroupArea = 0;
	
	for(int i = 0; i < pSize; i++)
	{
		totalGroupArea+=shapesPtr[i]->area();
		
	}
	
	return totalGroupArea;
}

//----GroupPerimeter-------------------
double Group::perimeter() const
{
	//total up all the shapes perimeters in the array
	double totalGroupPeri = 0;
	
	for(int i = 0; i < pSize; i++)
	{
		totalGroupPeri+=shapesPtr[i]->perimeter();
		
	}
	return totalGroupPeri;
	
}

//----GroupMove------------------------
void Group::move(double x, double y)
{		
	//call move for all types of shapes a move x, y times
	for(int i = 0; i < pSize; i++)
	{
		shapesPtr[i]->move(x, y);
		
	}
	
}

//----GroupRender----------------------
void Group::render(ostream& os) const
{
	//cout the first Color and size of the group then call the same render function on different shapes in the array
	os << "Group(" << colorList[Shape::color()] << "," << pSize;
	
	for(int i = 0; i < pSize; i++)
	{
		os << ",";
		shapesPtr[i]->render(os);
		
	}
	os << ")";

}

//----GroupInside----------------------
bool Group::inside(double x, double y) const
{	
	//check all insides for every shape, if its true ever then return true
	for(int i = 0; i < pSize; i++)
	{
		if(shapesPtr[i]->inside(x, y))
			return true;
		
	}
	return false;
}

//hey nathan :) you wont find a int main here
