// Given a time, calculate the angle between the hour and minute hands

/*
  BREAKING DOWN THE PROBLEM:
  We're going to use a technique called Examplifying, where we try to derive a
  general rule from a few examples.

  3:27 appears to have an angle of ~80 degrees between the two hands.
  The angle b/w noon and the hour hand appears to be ~100.
  The angle b/w noon and the minute hand appears to be ~175.
  175 - 100 = 75 (estimations, so close enough)

  Ok, a full circle is 360 degrees.
  So, if we pick an arbitrary pt, like 12:00, we can write a formula that
  calculates the angle between that vertical line and one of the hands.
  Let's start with the minute hand.
  There are 60 minutes per 360 degrees, so:
  ma = 360 * m / 60
  Now, the hour hand is a bit more complicated.
  Each "full" hour is 30 degrees [360 / 12].
  We need to find that "base" position (an int 0 to 11), then add the fraction
  of an hour that corresponds to the amount of minutes in the time.
  To find the base:
  bha = 360 * (h % 12) / 12
  To find the added minute portion:
  added_min = 30 * m / 60
  Now, the full equation for the hour hand is:
  ha = 360 * (h % 12) / 12  +  30 * m / 60
  ha = (360*h/12) % (360*12/12) + 0.5m
  ha = 30h + 0.5m
  If the angle we're looking for is b/w the hour and minute hand, then we can
  just find the difference between the two equations:
  answer = ha - ma
  answer = ((30h + 0.5m) - (360m / 60)) % 360
  answer = (30h + 0.5m - 6m) % 360
  answer = (30h - 5.5m) % 360

  QUICK TESTS:
  12:00 ----> (30*12 - 5.5*0) % 360 --> 360 % 360 --> 0 [pass]
  24:00 ----> (30*24 - 5.5*0) % 360 --> 720 % 360 --> 0 [pass]
  1:00  ----> (30*1 - 5.5*0) % 360  --> 30 % 360 --> 30 [pass]
  11:59 --> (30*12 - 5.5*59) % 360 --> 5.5 % 360 -> 5.5 [pass]

  CLARIFYING QUESTIONS TO ASK:
  How precise do we need to be? (ie, float vs double)?
  Do we want to avoid reflex angles (180 < a < 360)?
  Do we want to crash the program if an negative, or otherwise invalid input
  is passed to the function?
*/

#include <iostream>
#include <math.h>
#include <cmath>

float timeangle(int h, int m) { 
  // Console-log the input as HH:MM
  std::string hh;
  std::string mm;

  if (std::abs(h) < 10) hh = "0" + std::to_string(h);
  else hh = std::to_string(h);

  if (std::abs(m) < 10) mm = "0" + std::to_string(m);
  else mm = std::to_string(m);

  std::cout << hh << ":" << mm << std::endl;

  // Check for negative inputs
  if ((h < 0) || (m < 0)) {
    std::cerr
      << "error: args to timeangle(int h, int m) must be positive ints"
      << std::endl;
    return -1;
  }
  
  // Get angle between the two hands
  float answer = std::abs(fmod((30*h - 5.5*m), 360));
  answer = (answer < 180) ? answer : 360-answer;
  return answer;
}

int main() {
  // TESTS:

  // Standard inputs
  std::cout << timeangle(0, 45) << std::endl << std::endl;
  std::cout << timeangle(12, 00) << std::endl << std::endl;
  std::cout << timeangle(5, 30) << std::endl << std::endl;
  std::cout << timeangle(23, 59) << std::endl << std::endl;

  // User Errors (handling correctly?)
  std::cout << timeangle(-11, 59) << std::endl << std::endl;
  std::cout << timeangle(11, -59) << std::endl << std::endl;
  std::cout << timeangle(11, 59.0) << std::endl << std::endl;
  std::cout << timeangle(12, 59.0) << std::endl << std::endl;
  return 0;
}
  
