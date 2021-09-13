#include <Rcpp.h>

#include <vector>


void test(double* a, double* b) {
  // construct vector which has double** to double* as data representation for ode system

  std::vector<double> vec_a(a, a + 1); // copy
  std::vector<double> vec_b(b, b + 1);

  *a = vec_a[0] + vec_b[0];
  *b = vec_a[0] + vec_b[0];

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
