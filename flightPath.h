#include <string>
#include <stdlib.h>     /* atof */
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  double x, y;
  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  void print() {
    cout << "(" << x << ", " << y << ")" << endl;
  }
};

struct Line {
  double a, b;
  Line() {
    a = 0;
    b = 0;
  }

  Line(double a, double b) {
    this->a = a;
    this->b = b;
  }

  Line(Point p1, Point p2) {
    double x1, x2, y1, y2;
    x1 = p1.x;
    x2 = p2.x;
    y1 = p1.y;
    y2 = p2.y;

    a = (y1 - y2) / (x1 - x2);
    b = y1 - a * x1;
  }

  void print() {
    cout << "a = " << a << ", b = " << b << endl;
  }
};

class FlightPath {
public:
  int n;
  vector<Point> allPoints;

  FlightPath() {
    n = 0;
  }

  FlightPath(int n) {
    this->n = n;
  }

  void addPoint(double x, double y) {
    // cout << x << " " << y;
    allPoints.push_back(Point(x, y));
  }

  void printPoints() {
    for (int i = 0; i < allPoints.size(); i++) {
      allPoints[i].print();
    }
  }

  double distance(Point p, Line line) {
    double a, b, c, x, y;
    a = line.a;
    b = -1.0;
    c = line.b;
    x = p.x;
    y = p.y;

    return abs(a * x + b * y + c) / sqrt(a * a + b * b);
  }

  void findPath() {
    srand (time(NULL));
    double r1, r2;
    Point p1, p2;
    r1 = rand() % n;
    r2 = rand() % n;
    while(r2 == r1) { r2 = rand() % n; }
    p1 = allPoints[r1];
    p2 = allPoints[r2];

    p1.print();
    p2.print();

    Line line(p1, p2);
    line.print();

    double d1 = distance(p1, line);
    double d2 = distance(p2, line);

    cout << d1 << " " << d2 << endl;

  }

};









