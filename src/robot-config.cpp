#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain; // global instance of brain for printing to screen

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT5, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller(primary);

// VEXcode generated functions
bool RemoteControlCodeEnabled = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() 
{
  while (true) 
  {
    if(RemoteControlCodeEnabled) 
    {
      int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position();
      
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5)
      {
        if (DrivetrainLNeedsToBeStopped_Controller1)
        {
          LeftDriveSmart.stop();                            // stop the left drive motor
          DrivetrainLNeedsToBeStopped_Controller1 = false;  // tell the code that the left motor has been stopped
        }
      } 
      else 
      {
        DrivetrainLNeedsToBeStopped_Controller1 = true;     // reset toggle
      }
 
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) 
      {
        if (DrivetrainRNeedsToBeStopped_Controller1) 
        {
          RightDriveSmart.stop();
          DrivetrainRNeedsToBeStopped_Controller1 = false;  // tell the code that the right motor has been stopped

        }
      } else 
      {
        DrivetrainRNeedsToBeStopped_Controller1 = true;     // reset toggle
      }
      
      if (DrivetrainLNeedsToBeStopped_Controller1) 
      {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }

      if (DrivetrainRNeedsToBeStopped_Controller1) 
      {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
    }
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}