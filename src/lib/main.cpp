#include <iostream>

using namespace std;

#include "mo/SmellFinder.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "./mo <input file>" << endl;
    return 1;
  }
  string src(argv[1]);
  SmellFinder smellFinder;
  if (!smellFinder.hasSmell(src)) {
    cout << "No Smell Detected!" << endl;
  }
  return 0;
}
