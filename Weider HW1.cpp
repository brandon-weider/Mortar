//Program Written By: Brandon Weider
//Date: 09/05/2013
// This program is going to calculate the maximum range for the mortar (9 cranks),
// the height of the projectile at 8 cranks,
// and a launch height of how many meters to hit the target with 7 cranks
// important formulas
	// x = v*t (x=distance traveled), (v=velocity), (t=time)
	// x = v*t - (1/2)*g*(t^2) - indicates the effects of gravity
		// (x = net altitude), (v = initial velocity), (t = time), g = (downward effect due to gravity)
	// object hits ground when
		// v - (1/2)*g*t = 0
	// v = (crankRotations * ratio)
	// v = (x/t) = ratio

#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	cout << fixed << setprecision(2);
	double crankRatio;				   // the ratio the crank has with the velocity
	double velocity;		           // the velocity that the crank has per turn
	double calibrationDistance;		   // the distance traveled during calibration after one crank rotation
	double calibrationTime;			   // the time required for the crank to travel a distance
	double gravity;					   // the calculated gravity of the system
	double maximumDistance;			   // indicates the maximum range of the mortar (9 cranks)
	double mortarVelocity;			   // indicats the maximum velocity (9 cranks)
	double projectileHeight;		   // indicates the height of the projectile at 8 cranks
	double elevation;				   // indicates the elevation needed to hit the target at 750 meters
	double time;				       // time it takes for the object to hit the ground

	cout << "Please specify the distance traveled (in meters) during calibration: "; 
	cin >> calibrationDistance; // input by professor and found during calibration

	cout << "Please specify the time (in seconds) found during calibration: ";
	cin >> calibrationTime; // input by professor and found during calibration

	velocity = (calibrationDistance / calibrationTime);							// calculates the velocity based on the crankRotations to the ratio
	crankRatio = velocity;														// the ratio is directly equal to the velocity of the object since the calibration uses one crankRotation
	gravity = (2 * velocity / calibrationTime);									// calculated the gravity in the system based on velocity and time
	mortarVelocity = (9 * crankRatio);											// calculates the velocity at 9 cranks
	time = (2 * mortarVelocity / gravity);										// calculates the time it takes to reach the ground at 9 cranks
	maximumDistance = (mortarVelocity * time);									// calculates the maximum distance of the mortar
	mortarVelocity = (8 * crankRatio);											
	time = (750 / mortarVelocity);												// calculates the time it takes to travel 750m
	projectileHeight = time * (mortarVelocity - (gravity * time / 2));		    // calculates the height of the projectile at a 750m target
	mortarVelocity = (7 * crankRatio);
	time = (750 / mortarVelocity);
	elevation = -(time * (mortarVelocity - (gravity * time / 2)));              // calculates the elevation the mortar needs to be at 7 cranks



	cout << "The maximum range of the mortar is: " << maximumDistance << " meters." << endl
		 << "The height of the projectile when it reaches the 750m target is: " << projectileHeight << " meters off of the ground." << endl
		 << "To hit the target with only 7 cranks, the mortar needs to be " << elevation << " meters off of the ground." << endl;
	
	return 0;
}