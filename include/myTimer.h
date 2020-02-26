#ifndef MYTIMER_H
#define MYTIMER_H

#include <iostream>
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration = {};
	double endResult = 0.0;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		endResult = result();
		std::cout << endResult << "ms\n";
	}

	double result()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		endResult = (double)duration.count() * (double)1000.0f;
		return endResult;
	}
};

#endif // MYTIMER_H
