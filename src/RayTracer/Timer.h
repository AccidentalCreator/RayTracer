#pragma once
#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
	void StartCounter();
	double GetCounter();

private:
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
};

#endif // !TIMER_H
