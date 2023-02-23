#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    void setX(int x)
    {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    void print()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }

    ~Point()
    {
        cout << "Point destructor" << endl;
    }
};

class Circle : public Point
{
private:
    int radius;

public:
    Circle(int x, int y, int radius) : Point(x, y)
    {
        this->radius = radius;
    }

    int getRadius()
    {
        return radius;
    }

    void setRadius(int radius)
    {
        this->radius = radius;
    }

    void print()
    {
        cout << "x = " << getX() << ", y = " << getY() << ", radius = " << radius << ", area = " << getArea() << endl;
    }

    double getArea()
    {
        return 3.14 * radius * radius;
    }

    ~Circle()
    {
        cout << "Circle destructor" << endl;
    }
};

class Ellipse : public Circle
{
private:
    int radius2;

public:
    Ellipse(int x, int y, int radius, int radius2) : Circle(x, y, radius)
    {
        this->radius2 = radius2;
    }

    int getRadius2()
    {
        return radius2;
    }

    void setRadius2(int radius2)
    {
        this->radius2 = radius2;
    }

    void print()
    {
        cout << "x = " << getX() << ", y = " << getY() << ", radius = " << getRadius() << ", radius2 = " << radius2 << ", area = " << getArea()
             << endl;
    }

    double getArea()
    {
        return 3.14 * getRadius() * radius2;
    }

    ~Ellipse()
    {
        cout << "Ellipse destructor" << endl;
    }
};

int main()
{
    cout << "Point:" << endl;
    Point point(1, 2);
    point.print();
    point.setX(3);
    point.setY(4);
    point.print();

    cout << "Circle:" << endl;
    Circle circle(1, 2, 3);
    circle.print();
    circle.setX(4);
    circle.setY(5);
    circle.setRadius(6);
    circle.print();

    cout << "Ellipse:" << endl;
    Ellipse ellipse(1, 2, 3, 4);
    ellipse.print();
    ellipse.setX(5);
    ellipse.setY(6);
    ellipse.setRadius(7);
    ellipse.setRadius2(8);
    ellipse.print();

    return 0;
}