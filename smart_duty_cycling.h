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


#ifndef smart_duty_cycling_h
#define smart_duty_cycling_h


class smart_duty_cycling
{
public:

//bool flag;
bool wake;

void setWakeSleepPeriods(int val1, int val2);
void setFrequencyDutyCycle(float freq, float dutyCycle);
void setWakePeriod(int val);
void setSleepPeriod(int val);
void setReference(long val);
void setFrequency(float freq);
void setDutyCycle(float dutyCycle);

bool switchMode();

smart_duty_cycling();


protected:

int sleep_period;
int wake_period;
long reference_time; 
float time_period;
float duty_cycle;
    
};

#endif
