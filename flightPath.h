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

  }

};









