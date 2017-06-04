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
    for (int i = 0; i < n; i++) {
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

  double findMedianDist(vector<double> allDistances) {
    sort(allDistances.begin(), allDistances.end());
    if (n % 2 == 0) {
      return (allDistances[n / 2 - 1] + allDistances[n / 2]) / 2;
    } else {
      return allDistances[n / 2];
    }
  }

  void findPath() {
    srand (time(NULL));
    double r1_rand, r2_rand, medianDist;
    Line path;
    double MinmedianDist = 999999999;
    Point p1, p2;

    for (int k = 0; k < n; k++) {
      r1_rand = rand() % n;
      r2_rand = rand() % n;
      while(r2_rand == r1_rand) { r2_rand = rand() % n; }
      p1 = allPoints[r1_rand];
      p2 = allPoints[r2_rand];

      // p1.print();
      // p2.print();

      Line line(p1, p2);
      // line.print();

      vector<double> allDistances;
      for (int i = 0; i < n; i++) {
        allDistances.push_back(distance(allPoints[i], line));
      }

      // for (int i = 0; i < n; i++) {
      //   cout << allDistances[i] << " ";
      // }
      // cout << endl;

      medianDist = findMedianDist(allDistances);
      if (medianDist < MinmedianDist) {
        MinmedianDist = medianDist;
        path = line;
      }
    }

    cout << "MinmedianDist = " << MinmedianDist << endl;
    path.print();

  }

};









