// TODO: Probelm Driving Time, distance and speed given calculate time

#include <stdio.h>
void main() {
  float distance, speed, time;
  distance = 101;  // km
  speed = 50;      // km/hr

  float speedInMetersPerSecond = speed * 1000 / 3600;
  float distanceInMeters = distance * 1000;

  time = distanceInMeters / speedInMetersPerSecond;
  float timeInHours = time / 3600;
  float remainingTimeInMinutes = (timeInHours - (int)timeInHours) * 60;

  printf("Time taken to travel %f km at %f km/hr is %d hours and %f minutes",
         distance, speed, (int)timeInHours, remainingTimeInMinutes);
}