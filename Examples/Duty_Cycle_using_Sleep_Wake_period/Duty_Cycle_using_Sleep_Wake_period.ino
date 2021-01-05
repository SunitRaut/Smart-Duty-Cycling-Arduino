// **********************************************************************************
// Author: Sunit Raut   github.com/SunitRaut
// **********************************************************************************
// License
// **********************************************************************************
// This program is free software; you can redistribute it 
// and/or modify it under the terms of the GNU General    
// Public License as published by the Free Software       
// Foundation; either version 3 of the License, or        
// (at your option) any later version.                    
//                                                        
// This program is distributed in the hope that it will   
// be useful, but WITHOUT ANY WARRANTY; without even the  
// implied warranty of MERCHANTABILITY or FITNESS FOR A   
// PARTICULAR PURPOSE. See the GNU General Public        
// License for more details.                              
//                                                        
// Licence can be viewed at                               
// http://www.gnu.org/licenses/gpl-3.0.txt
//
// Please maintain this license information along with authorship
// and copyright notices in any redistribution of this code
// **********************************************************************************
// Example: Generate Duty Cycle using Wake Period and Sleep Period as inputs
// **********************************************************************************


#include <smart_duty_cycling.h>

smart_duty_cycling cycle;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cycle.setWakeSleepPeriods(1000,4000); // Wake and Sleep period respectively in milliseconds
  //Alternative Declaration
  //cycle.setWakePeriod(1000);    // Wake period in milliseconds
  //cycle.setSleepPeriod(4000);   // Sleep Period in milliseconds
}

void loop() {
  // put your main code here, to run repeatedly:
  if(cycle.switchMode())
  {
     if(cycle.wake)
     {
       Serial.println(F("Wake Period")); 
       //Perform operation in Wake / Active / ON time
     }
     else
     {
       Serial.println(F("Sleep Period"));
       //Perform operation in Sleep / Inactive / OFF time
     }
  }
}
