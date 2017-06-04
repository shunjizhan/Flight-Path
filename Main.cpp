#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atof */
#include "flightPath.h"
using namespace std;

int main() {
  int n;
  string x, y;
  double X, Y;

  cin >> n;
  FlightPath f(n);

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    X = atof(x.c_str());
    Y = atof(y.c_str());

    // cout << X << " " << Y << endl;
    f.addPoint(X, Y);
  }
  f.printPoints();

  f.findPath();

  return 0;
}