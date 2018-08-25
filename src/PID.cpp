#include "PID.h"
#include <cmath>

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
  
  // for twiddle
  dp.push_back(Kp/100); 
  dp.push_back(Ki/100);
  dp.push_back(Kd/100);
  step = 1;
  b_error = 0.0;
  iter = 0;
  n = 50;
}

void PID::UpdateError(double cte) {
  d_error = cte-p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  double t_error = p_error + i_error + d_error;
  t_error = abs(t_error);
  return t_error;
}

void PID::Twiddle() {
  vector<double> p;
  p.push_back(Kp);
  p.push_back(Ki);
  p.push_back(Kd);
  
  if (step == 1) {
    b_error = TotalError();
    p[iter] += dp[iter];
    Kp = p[0];
    Ki = p[1];
    Kd = p[2];
    step = 2;
  }
  else if (step == 2) {
    double t_error = TotalError();
    if ( t_error < b_error ) {
      b_error = t_error;
      dp[iter] *= 1.01;
      step = 1;
      iter += 1;
      if (iter == 3) {
        iter = 0;
      }
    }
    else {
      p[iter] -= 2 * dp[iter];
      Kp = p[0];
      Ki = p[1];
      Kd = p[2];
      step = 3;
    }
  }
  else if (step == 3) {
    double t_error = TotalError();
    if ( t_error < b_error ) {
      b_error = t_error;
      dp[iter] *= 1.01;
      step = 1;
      iter += 1;
      if (iter == 3) {
        iter = 0;
      }
    }
    else {
      p[iter] += dp[iter];
      Kp = p[0];
      Ki = p[1];
      Kd = p[2];
      dp[iter] *= 0.99;
      step = 1;
      iter += 1;
      if (iter == 3) {
        iter = 0;
      }
    }
  }
}

