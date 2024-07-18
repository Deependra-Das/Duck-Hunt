#include "../../Header/Time/TimeService.h"

namespace Time
{
	void TimeService::initialize()
	{
		previous_time = std::chrono::steady_clock::now();
		delta_time = 0;
	}

	void TimeService::update()
	{
		updateDeltaTime();
	}

	float TimeService::getDeltaTime()
	{
		return delta_time;
	}

	void TimeService::updateDeltaTime()
	{
		delta_time = calculateDeltaTime();
		updatePreviousTime();
	}

	float TimeService::calculateDeltaTime()
	{
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();

		return static_cast<float>(delta) / static_cast<float>(1000000);
	}

	void TimeService::updatePreviousTime()
	{
		previous_time = std::chrono::steady_clock::now();
	}
}