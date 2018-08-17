#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double b_error; // for twiddle

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  vector<double> dp; // for twiddle
  int step; // for twiddle
  int iter; // for twiddle
  
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  // Twiddle
  void Twiddle();

#endif /* PID_H */
