#include <iomanip>
#include <iostream>
#include <cmath>


enum Color { BLACK=0, RED=1, GREEN=2, YELLOW=3, BLUE=4, MAGENTA=5, CYAN=6, WHITE=7, INVALID=8 };


class Shape{
	private:
		Color pColor;
		Shape(const Shape& s);
		const Shape& operator=( const Shape& o);
		
	public:
		//Constructor
		Shape(Color c);
		virtual ~Shape() = 0;
		
		//Getter
		Color color() const;
		
		//Setter
		virtual void color(Color c);

		//adding virtual ... = 0; let them be overwritten and makes the Shape class abstract (pure virtual)
		virtual double area() const = 0; 
		virtual double perimeter() const = 0;
		virtual void move(double x, double y) = 0;
		virtual void render(std::ostream& os) const = 0;
		virtual bool inside(double x, double y) const = 0;
		double thickness(); 
		static Color colorAtPoint(Shape** list, int size, double x, double y);

};

//----------------------------------------------------------------------
class Box : public Shape
{
	private:
		double pLeft;
		double pRight;
		double pTop;
		double pBottom;
		
	public:
		//-----Constructor---
		Box(Color c, double l, double t, double r, double b);

		//-----Getters-------
		double left() const; 
		double right() const;
		double top() const;
		double bottom() const;
		
		//-----Setters-------
		void left( double l );
		void right( double r );
		void top( double t );
		void bottom( double b );
		
		double area() const;
		double perimeter() const;
		void move( double x, double y );
		void render( std::ostream& os ) const;
		bool inside( double x, double y ) const;
		
};

//-------------------------------------------------------------
class RoundBox : public Shape
{
	private:
		double pLeft;
		double pRight;
		double pTop;
		double pBottom;
		double pRadius;
		
	public:
		//-----Constructor---
		RoundBox(Color c, double l, double t, double r, double b, double radius);

		//-----Getters-------
		double left() const; 
		double right() const;
		double top() const;
		double bottom() const;
		double radius() const;
		
		//-----Setters-------
		void left( double l );
		void right( double r );
		void top( double t );
		void bottom( double b );
		void radius( double radius);
		
		double area() const;
		double perimeter() const;
		void move( double x, double y );
		void render( std::ostream& os ) const;
		bool inside( double x, double y ) const;
		
};

//---------------------------------------------------------------------
class Circle : public Shape
{
	private:
		double pX;
		double pY;
		double pRadius;
		
	public:
		//-----Constructor---
		Circle(Color c, double center_X, double center_Y, double radiusOfCircle);

		//-----Getters-------
		double centerX() const; 
		double centerY() const;
		double radius() const;
		
		//-----Setters-------
		void centerX(double center_X);
		void centerY(double center_Y);
		void radius (double radiusOfCircle);
		
		double area() const;
		double perimeter() const;
		void move(double x, double y);
		void render(std::ostream& os) const;
		bool inside(double x, double y) const;

};

//------------------------------------------------------------------
class Triangle : public Shape
{
	private:
		double pX1, pY1;
		double pX2, pY2;
		double pX3, pY3;
		
	public:
		//-----Constructor---
		Triangle(Color c,
		double x_1, double y_1,
		double x_2, double y_2,
		double x_3, double y_3);		

		//-----Getters-------
		double cornerX1() const;
		double cornerY1() const;
		double cornerX2() const;
		double cornerY2() const;
		double cornerX3() const;
		double cornerY3() const;
		
		//-----Setters-------
		void cornerX1(double X_1);	
		void cornerY1(double Y_1);
		void cornerX2(double X_2);	
		void cornerY2(double Y_2);
		void cornerX3(double X_3); 	
		void cornerY3(double Y_3);	
		
		double area() const;
		double perimeter() const;
		void move(double x, double y);
		void render(std::ostream& os) const;
		bool inside(double x, double y) const;
		
};

//-----------------------------------------------------------------------
class Polygon : public Shape
{
	private:
		int pSize;
		double* corners;
	
	public:
		//-----Constructor
		Polygon(Color c, double* pts, int size);
		~Polygon();
		
		//-----Getters-------
		int points() const;
		double vertexX(int index) const;
		double vertexY(int index) const;
	
		//-----Setters-------
		void vertexX(int index, double x);
		void vertexY(int index, double y);
	
		double area() const;
		double perimeter() const;
		void move(double x, double y);
		void render(std::ostream& os) const;
		bool inside(double x, double y) const;
		
};

//----------------------------------------------------------------------
class Line : public Shape
{
	private:
		double pX1, pY1; //x1, y2
		double pX2, pY2; //x2, y2
	
	public:
		//-----Constructor---
		Line(Color c, double x1, double y1, double x2, double y2);

		//-----Getters-------
		double end1X() const; double end1Y() const;//x1, y1
		double end2X() const; double end2Y() const;//x2, y2
		
		//-----Setters-------
		void end1X(double x1); void end1Y(double y1);//x1, y1
		void end2X(double y2); void end2Y(double y2);//x2, y2
		
		double area() const;
		double perimeter() const;
		void move( double x, double y );
		void render( std::ostream& os ) const;
		bool inside( double x, double y ) const;
		
};

//----------------------------------------------------------------------
class Group : public Shape
{
	private:
		int pSize;
		Shape** shapesPtr;
	
	public:
		//-----Constructor---
		Group(Color c, int size, Shape** list);
		~Group();
		
		//-----Getter-------
		Shape* shape(int N) const;
		
		//-----Setter-------
		void color(Color c);
		
		double area() const;
		double perimeter() const;
		void move( double x, double y );
		void render( std::ostream& os ) const;
		bool inside( double x, double y ) const;
		int shapes() const;
		void shapes(int size, Shape** list);
		
		
};