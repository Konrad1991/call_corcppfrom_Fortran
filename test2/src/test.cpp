#include <Rcpp.h>




void test(double* a, double* b) {
  // construct vector which has double** to double* as data representation for ode system
  *a = (*a) + (*b);
  *b = (*a) + (*b);
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
