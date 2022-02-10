#include "vex.h"
using namespace vex;



class Tasks
{
  // collection of autonomous tasks
  public:
    
    void easyMaze()
    {
      int turn = 105;
      Brain.Screen.print("Run easy maze...");
      Brain.Screen.newLine();

      Drivetrain.driveFor(2050, mm, true);
      Brain.Screen.clearLine();
      Brain.Screen.print("D2050 ");
      
      Drivetrain.turnFor(105, degrees, true);
      Brain.Screen.clearLine();
      Brain.Screen.print("T105");

      Drivetrain.driveFor(1100, mm, true);
      Brain.Screen.clearLine();
      Brain.Screen.print("D1100 ");
      
      Drivetrain.turnFor(103, degrees, true); 
      Brain.Screen.clearLine();
      Brain.Screen.print("T103");
      
      Drivetrain.driveFor(2000, mm, true);
      Brain.Screen.clearLine();
      Brain.Screen.print("D2050");

      Drivetrain.turnFor(turn, degrees, true); 
      Brain.Screen.clearLine();
      Brain.Screen.print("T105");
      
      Brain.Screen.clearLine();
      Brain.Screen.print("Done");
      Brain.Screen.newLine(); 
    }

    void parking()
    {

    }

    void chair()
    {

    }

    void stool()
    {

    }


};



int main() 
{  
  Tasks tasks; // create tasks object

  Brain.Screen.print("Ready");
  Brain.Screen.newLine();

  vexcodeInit();
  while(true)
  {


    // figure out if tasks need too be run
    if (Controller1.ButtonL2.pressing() == true && Controller1.ButtonR2.pressing() == true)
    {
      if (Controller1.ButtonX.pressing() == true)
      {
        tasks.easyMaze();
        wait(1000, msec); // don't want to have this execute many timest
      }
      else if (Controller1.ButtonY.pressing() == true)
      {
        tasks.parking();
        wait(1000, msec);
      }
      else if (Controller1.ButtonA.pressing() == true)
      {
        tasks.chair();
        wait(1000, msec);
      }
      else if (Controller1.ButtonB.pressing() == true)
      {
        tasks.stool();
        wait(1000, msec);
      }
    }

    wait(20, msec); // don't remove
  }
}
