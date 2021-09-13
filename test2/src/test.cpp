#include <Rcpp.h>

#include <vector>
#include <functional>


void test(double* a, double* b) {
  // construct vector which has double** to double* as data representation for ode system

  std::vector<double> vec_a(a, a + 1); // copy
  std::vector<double> vec_b(b, b + 1);

  *a = vec_a[0] + vec_b[0];
  *b = vec_a[0] + vec_b[0];

  //std::vector<std::reference_wrapper<double>> vec_a2(a, a + 1);
  //std::vector<std::reference_wrapper<double>> vec_b2(b, b + 1);

  //std::reference_wrapper<double> rw_a = *a;

  //*a = (*a) + (*b);
  //*b = (*a) + (*b);
}

extern "C" {
  void fct(double* a, double* b) {
    test(a, b);
  }
}

extern "C" {
  void test_();
}

// [[Rcpp::export]]
void call() {
  test_();
}
