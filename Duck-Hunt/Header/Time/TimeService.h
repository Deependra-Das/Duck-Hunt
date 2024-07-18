#pragma once

#include <chrono>

namespace Time
{
	class TimeService
	{
	private:
		std::chrono::time_point<std::chrono::steady_clock> previous_time;

		float delta_time;

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:

		void initialize();
		void update();

		float getDeltaTime();
	};
}