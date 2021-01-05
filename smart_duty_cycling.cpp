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


#include <smart_duty_cycling.h>
#include <Arduino.h>






smart_duty_cycling::smart_duty_cycling()	//Constructor
{
	//Default values initialized
	reference_time = 0;
	wake_period = 1000;
	sleep_period = 1000;
	wake = false;
}


void smart_duty_cycling::setWakePeriod(int val)
{
	wake_period = val;
}

void smart_duty_cycling::setSleepPeriod(int val)
{
	sleep_period = val;
}

void smart_duty_cycling::setReference(long val)
{
	reference_time = val;
}

void smart_duty_cycling::setWakeSleepPeriods(int val1, int val2)
{
	wake_period = val1;
	sleep_period = val2;
}

void smart_duty_cycling::setFrequencyDutyCycle(float freq, float dutyCycle)
{
	duty_cycle = dutyCycle;
	
	time_period = (1/freq)*1000;		//convert frequency to time in milliseconds
	
	wake_period = duty_cycle*time_period;
	sleep_period = (1-duty_cycle)*time_period;
	 	
}

void smart_duty_cycling::setFrequency(float freq)
{
	time_period = (1/freq)*1000;		//convert frequency to time in milliseconds
	
	wake_period = duty_cycle*time_period;
	sleep_period = (1-duty_cycle)*time_period;
}


void smart_duty_cycling::setDutyCycle(float dutyCycle)
{
	duty_cycle = dutyCycle;
	
	wake_period = duty_cycle*time_period;
	sleep_period = (1-duty_cycle)*time_period;
}



bool smart_duty_cycling::switchMode()
{	
	//Check the time with respect to current cycle
	long time_now = ( millis() - reference_time ) % ( wake_period + sleep_period ) ;	 
	
	//Check if wake or sleep currently
	bool wake_temp = (time_now<wake_period)?true:false;
	
	// Check if wake mode has switched and return acccordingly
	if(wake_temp==wake) 
	{
		wake = wake_temp;
		return false;
	}
	else 
	{
		wake = wake_temp;
		return true;
	}
}  

