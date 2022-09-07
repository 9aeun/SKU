#pragma once
#include <iostream>
using namespace std;

class Figure {	//move와 draw 때문에 virtual attribute임
private:	//member변수 private 하게
	int color;
public:
	void setColor(int c) { color = c; }
	virtual void move(int dx, int dy) = 0; // abstract operation, = 0을 붙여야 함 즉 =0 을 붙이면 추상 operation임.
	virtual void draw() = 0; // abstract operation
	Figure(int c) {
		color = c;
		cout << "Figure::Figure()" << endl;
	}
	virtual ~Figure() {	
		cout << "Figure::~Figure()\n";
	}
};

class Point {
	int x, y;
public:
	void move(int dx, int dy) {
		x += dx;
		y += dy;
		cout << "Point::move()\n";
	}
	Point(int xp, int yp) {
		x = xp;
		y = yp;
		cout << "Point::Point()\n";
	}
	~Point() { cout << "Point::~Point()\n"; }
};

class Circle : public Figure {	//circle이 point객체를 갖고 있음
	Point center;
	int radius;
public:
	void move(int dx, int dy) {	
		center.move(dx, dy);
		cout << "Circle::move()\n";
	}
	void draw() { cout << "Circle::draw()\n"; }
	void setRadius(int r) { radius = r; }
	Circle(int x, int y, int r, int c) : Figure(c), center(x, y) {
		radius = r;
		cout << "Circle::Circle()\n";
	}
	~Circle() { cout << "Circle::~Circle()\n"; }
};

class Rectangle : public Figure {
	Point topleft;
	int width, height;
public:
	void move(int dx, int dy) {	//circle과 구현이 다르다
		topleft.move(dx, dy);
		cout << "Rectangle::move()\n";
	}
	void draw() { cout << "Rectangle::draw()\n"; }	//circle과 구현이 다르다
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	Rectangle(int x, int y, int w, int h, int c) : Figure(c), topleft(x, y) {
		width = w; height = h;
		cout << "Rectangle::Rectangle()\n";
	}
	~Rectangle() { cout << "Rectangle::~Rectangle()\n"; }
};

int main() {
	Figure* f[10];	//figure을 가리킬 수 있는 pointer , figure는 circle과 rectangle을 둘 다 가리킬 수 있음.
	int num = 4;
	f[0] = new Circle(100, 100, 50, 2);
	f[1] = new Circle(200, 200, 30, 2);
	f[2] = new Rectangle(10, 10, 50, 40, 3);
	f[3] = new Rectangle(100, 100, 70, 30, 4);
	int dx = 10, dy = 20, i;
	for (i = 0; i < num; i++)
		f[i]->move(dx, dy); // polymorphism(다형성), circle과 rectangle에 따라서 알아서 구현 된다
	for (i = 0; i < num; i++)
		f[i]->draw(); // polymorphism
	for (i = 0; i < num; i++)
		delete f[i];
}
