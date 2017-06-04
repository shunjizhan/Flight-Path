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

  }

};









