#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Point{
public:
	double x,y;
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}

	double distance_to(Point *p){
		double dx = x - p->x;
		double dy = y - p->y;
		return sqrt(dx*dx + dy*dy);
	}
};

class Polygon{
protected:
		vector<Point*> vertices;
public:
	virtual int num_sides(void)=0;
	virtual double area(void)=0;
	virtual double perimeter(void)=0;
	vector<Point*> get_vertices(void){
		return this->vertices;
	}	
};

class Triangle:public Polygon{
	double a,b,c;
public:
	Triangle(Point *x, Point *y, Point *z){
		this->a = x->distance_to(y);
		this->b = y->distance_to(z);
		this->c = z->distance_to(x);
		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z);
	}
	
	int num_sides(void){
		return 3;
	}

	double area(void){
		double s = (a + b + c) / 2.0f;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	double perimeter(void){
		return a + b + c;
	}
};

class Quadrilateral:public Polygon{
	double a,b,c,d;
public:
	Quadrilateral(Point *x, Point *y, Point *z, Point *w){
		this->a = x->distance_to(y);
		this->b = y->distance_to(z);
		this->c = z->distance_to(w);
		this->d = z->distance_to(x);
		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(w);
	}

	int num_sides(void){
		return 4;
	}

	double area(void){
		Triangle *s = new Triangle(vertices[0], vertices[1], vertices[3]);
		Triangle *t = new Triangle(vertices[1], vertices[2], vertices[3]);
		double area = s->area() + t->area();
		delete s;
		delete t;
		return area;
	}

	double perimeter(void){
		return a+b+c+d;
	}
};

class PolygonFactory{
public:
	Polygon* create_polygon(vector<Point*> vertices){
		Polygon *p;
		if (vertices.size() == 3){
			p = new Triangle(vertices[0], vertices[1], vertices[2]);
		} else if (vertices.size() == 4){
			p = new Quadrilateral(vertices[0], vertices[1], vertices[2], vertices[3]);
		}
		return p;
	}
};

int main(){
	Point *x = new Point(0.0, 0.0);
	Point *y = new Point(3.0, 0.0);
	Point *z = new Point(0.0, 4.0);
	vector<Point*> v;
	v.push_back(x);
	v.push_back(y);
	v.push_back(z);
	PolygonFactory *factory = new PolygonFactory();
	Polygon *p = factory->create_polygon(v);
	cout << "Number of sides of polygon = " << p->num_sides() << endl;
	cout << "Area = " << p->area() << endl;
	v.pop_back();
	Point *w = new Point(3.0, 4.0);
	v.push_back(w);
	v.push_back(z);
	p = factory->create_polygon(v);
	cout << "Number of sides of polygon = " << p->num_sides() << endl;
	cout << "Area = " << p->area() << endl;
	return 0;
}