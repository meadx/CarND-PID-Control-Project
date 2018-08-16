#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
}

void PID::UpdateError(double cte) {
  d_error = cte-p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  double t_error = p_error + i_error + d_error;
  
  /*
  if (t_error > 0.2) {
    double[] p = [Kp, Kd, Ki];
    double[] dp = [1.0, 1.0, 1.0];
      for (int i=0; i<p.size(); i++) {
        p[i] += dp[i];
      }
  }
  */
  
  return t_error;
}

