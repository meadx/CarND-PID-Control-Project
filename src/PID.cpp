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
  
  // for twiddle
  for (int i = 0; i<3; i++){
    dp.push_back(1.0); 
  }
  step = 1;
  b_error = 0.0;
  iter = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte-p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  double t_error = p_error + i_error + d_error;
  }
  
  return t_error;
}

void PID::Twiddle() {
  vector<double> p;
  p.push_back(Kp);
  p.push_back(Kd);
  p.push_back(Ki);
  
  if (step == 1) {
    b_error = TotalError();
    p[iter] += dp[iter];
    Kp = p[0];
      Kd = p[1];
      Ki = p[2];
    step = 2;
  }
  else if (step == 2) {
    double t_error = TotalError();
    if ( t_error < b_error ) {
      b_error = t_error;
      dp[iter] *= 1.1;
      step = 1;
      iter += 1;
      if (iter == 3) {
        iter = 0;
      }
    }
    else {
      p[iter] -= 2 * dp[iter];
      Kp = p[0];
      Kd = p[1];
      Ki = p[2];
      step = 3;
    }
  }
  else if (step == 3) {
    double t_error = TotalError();
    if ( t_error < b_error ) {
      b_error = t_error;
      dp[iter] *= 1.1;
      step = 1;
      iter += 1;
      if (iter == 3) {
        iter = 0;
      }
    }
    else {
      p[i] += dp[i];
      Kp = p[0];
      Kd = p[1];
      Ki = p[2];
      dp[i] *= 0.9;
      step = 1;
      iter += 1;
      if (iter == 3) {
        iter = 0;
      }
    }
  }
}

