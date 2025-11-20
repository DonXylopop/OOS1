
#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren
class Point{
    double _x,_y;
public:
    Point(double x = 0, double y = 0):_x{x},_y{y}
    {

    }
    double get_x(){
        return _x;
    }
    double get_y(){
        return _y;
    }
    void set_x(double x){
        _x = x;
    }
    void set_y(double y){
        _y = y;
    }
    void move(double x, double y){
        _x += x;
        _y += y;
    }
    void print(bool enter = true){
        cout << "(" << _x << ", " << _y << ")";
        if(enter){
            cout << "\n";
        }
    }

};

class Circle{
    Point _center;
    double _radius;
public:
    Circle(Point p, double r = 1){
        _center.set_x(p.get_x());
        _center.set_y(p.get_y());
        _radius = r;
    }
    Point get_center(){
        return _center;
    }
    double get_radius(){
        return _radius;
    }
    void set_center(Point p){
        _center.set_x(p.get_x());
        _center.set_y(p.get_y());
    }
    void set_radius(double r){
        _radius = r;
    }
    void move(double x, double y){
        _center.set_x(_center.get_x() + x);
        _center.set_y(_center.get_y() + y);
    }
    void print(bool enter = true){
        cout << "[(" << _center.get_x() << ", " << _center.get_y() << "), " << _radius << "]";
        if(enter){
            cout <<"\n";
        }
    }

};

// Hauptprogramm
int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_center(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}

