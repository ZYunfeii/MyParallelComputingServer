//
// File: myinverse.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Mar-2022 14:55:33
//

// Include Files
#include "myinverse.h"
#include <cmath>

// Function Definitions

//
// Arguments    : const coder::array<double, 2U> *src
//                coder::array<double, 2U> *res
// Return Type  : void
//
void myinverse(const coder::array<double, 2U> &src, coder::array<double, 2U>
               &res)
{
  int b_n;
  coder::array<double, 2U> x;
  coder::array<int, 2U> ipiv;
  int yk;
  coder::array<int, 2U> p;
  int ix;
  if ((src.size(0) == 0) || (src.size(1) == 0)) {
    res.set_size(src.size(0), src.size(1));
    b_n = src.size(0) * src.size(1);
    for (int i = 0; i < b_n; i++) {
      res[i] = src[i];
    }
  } else {
    int n;
    int i;
    int k;
    int ldap1;
    int u1;
    int j;
    int i1;
    int b_i;
    n = src.size(0);
    res.set_size(src.size(0), src.size(1));
    b_n = src.size(0) * src.size(1);
    for (i = 0; i < b_n; i++) {
      res[i] = 0.0;
    }

    x.set_size(src.size(0), src.size(1));
    b_n = src.size(0) * src.size(1);
    for (i = 0; i < b_n; i++) {
      x[i] = src[i];
    }

    b_n = src.size(0);
    ipiv.set_size(1, src.size(0));
    ipiv[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      ipiv[k - 1] = yk;
    }

    ldap1 = src.size(0);
    b_n = src.size(0) - 1;
    u1 = src.size(0);
    if (b_n < u1) {
      u1 = b_n;
    }

    for (j = 0; j < u1; j++) {
      int mmj_tmp;
      int jj;
      int jp1j;
      double smax;
      mmj_tmp = n - j;
      yk = j * (n + 1);
      jj = j * (ldap1 + 1);
      jp1j = yk + 2;
      if (mmj_tmp < 1) {
        b_n = -1;
      } else {
        b_n = 0;
        if (mmj_tmp > 1) {
          ix = yk;
          smax = std::abs(x[jj]);
          for (k = 2; k <= mmj_tmp; k++) {
            double s;
            ix++;
            s = std::abs(x[ix]);
            if (s > smax) {
              b_n = k - 1;
              smax = s;
            }
          }
        }
      }

      if (x[jj + b_n] != 0.0) {
        if (b_n != 0) {
          b_n += j;
          ipiv[j] = b_n + 1;
          ix = j;
          for (k = 0; k < n; k++) {
            smax = x[ix];
            x[ix] = x[b_n];
            x[b_n] = smax;
            ix += n;
            b_n += n;
          }
        }

        i = jj + mmj_tmp;
        for (b_i = jp1j; b_i <= i; b_i++) {
          x[b_i - 1] = x[b_i - 1] / x[jj];
        }
      }

      b_n = yk + n;
      yk = jj + ldap1;
      for (jp1j = 0; jp1j <= mmj_tmp - 2; jp1j++) {
        smax = x[b_n];
        if (x[b_n] != 0.0) {
          ix = jj + 1;
          i = yk + 2;
          i1 = mmj_tmp + yk;
          for (b_i = i; b_i <= i1; b_i++) {
            x[b_i - 1] = x[b_i - 1] + x[ix] * -smax;
            ix++;
          }
        }

        b_n += n;
        yk += n;
      }
    }

    b_n = src.size(0);
    p.set_size(1, src.size(0));
    p[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      p[k - 1] = yk;
    }

    i = ipiv.size(1);
    for (k = 0; k < i; k++) {
      i1 = ipiv[k];
      if (i1 > k + 1) {
        b_n = p[i1 - 1];
        p[i1 - 1] = p[k];
        p[k] = b_n;
      }
    }

    for (k = 0; k < n; k++) {
      i = p[k];
      res[k + res.size(0) * (i - 1)] = 1.0;
      for (j = k + 1; j <= n; j++) {
        if (res[(j + res.size(0) * (i - 1)) - 1] != 0.0) {
          i1 = j + 1;
          for (b_i = i1; b_i <= n; b_i++) {
            res[(b_i + res.size(0) * (i - 1)) - 1] = res[(b_i + res.size(0) * (i
              - 1)) - 1] - res[(j + res.size(0) * (i - 1)) - 1] * x[(b_i +
              x.size(0) * (j - 1)) - 1];
          }
        }
      }
    }

    for (j = 0; j < n; j++) {
      b_n = n * j - 1;
      for (k = n; k >= 1; k--) {
        yk = n * (k - 1) - 1;
        i = k + b_n;
        if (res[i] != 0.0) {
          res[i] = res[i] / x[k + yk];
          for (b_i = 0; b_i <= k - 2; b_i++) {
            i1 = (b_i + b_n) + 1;
            res[i1] = res[i1] - res[i] * x[(b_i + yk) + 1];
          }
        }
      }
    }
  }
}

//
// File trailer for myinverse.cpp
//
// [EOF]
//
