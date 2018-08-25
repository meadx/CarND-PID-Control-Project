Reflection of CarND-PID-Control-Project

I found my hyperparameters with a combination of trying and twiddle.
First I tried different static combinations.

Describe the effect each of the P, I, D components had in your implementation. #################
The inital set of P=1.0, I=1.0, D=1.0 let the car drove straight to the left and then straight to the right,
so that it drove out of the lane.
So I tried a lot of combinations and found that P=0.1, I=0.001, D=1.0 was working good.
The following happens when I had different parameters:
P=0.5, I=0.001, D=1.0 --> car was a fast pendulum from left lane line to right lane line
P=0.01, I=0.001, D=1.0 --> car was a slow pendulum from left lane line to right lane line
P=0.1, I=0.01, D=1.0 --> car drove straight to the left and to the right, so that it drove out of the lane
P=0.1, I=0.0001, D=1.0 --> car drove more to the outer lane lines at bends
P=0.1, I=0.001, D=5.0 --> car drove more disturbed
P=0.1, I=0.001, D=0.5 --> car was a slow pendulum from left lane line to right lane line

Describe how the final hyperparameters were chosen. ############################################
The final hyperparameter where choosen by a implementation of twiddle.
I started with P=0.1, I=0.001, D=1.0 and let the car drive for some laps.
Then the values where P=0.115423, I=0.00113157, D=1.15629.
