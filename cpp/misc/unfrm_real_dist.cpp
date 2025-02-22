// uniform_real_distribution
#include <iostream>
#include <random>

int main() {
  const int nrolls = 100;     // number of experiments
  const int nstars = 95;      // maximum number of stars to distribute
  const int nintervals = 10;  // number of intervals

  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  int p[nintervals] = {};

  double k = 0.3;

  for (int i = 0; i < nrolls; ++i) {
    double number = distribution(generator);
    std::cout << number << "(";
    if (number >= 0.0 && number <= 1.0) {
      if (number < k) {
        std::cout << "<";
      } else {
        std::cout << ">";
      }
      std::cout << ")\t";

    } else {
      std::cout << "out of bounds" << std::endl;
    }

    // ++p[int(nintervals * number)];
  }
  std::cout << std::endl;

  // std::cout << "uniform_real_distribution (0.0,1.0):" << std::endl;
  // std::cout << std::fixed;
  // std::cout.precision(1);

  // for (int i = 0; i < nintervals; ++i) {
  //   std::cout << float(i) / nintervals << "-" << float(i + 1) / nintervals
  //             << ": ";
  //   std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
  // }

  return 0;
}