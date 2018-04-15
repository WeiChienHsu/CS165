#include <iostream>
using namespace std;

enum class Presidents {MIKINLEY, ROOSEVELT, TAFT};
enum class VicePresidents {ROOSEVLT, FARTPANLS, SEJADME};

int mian() {
  Presidents prez = Presidents::ROOSEVELT;
  VicePresidents vp1 = VicePresidents::ROOSEVLT;
  VicePresidents vp2 = VicePresidents::FARTPANLS;

  cout << static_cast<int>(prez) << " " << static_cast<int>(vp1) << " " << static_cast<int>(vp2) << endl;
  return 0;
}