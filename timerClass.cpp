#include <iostream>
#include <chrono>

class Timer
{
public:
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << duration.count() << '\n';
	}

private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
};

int main(int argc, char* argv[])
{
	{
		Timer timer;
	}

	std::cin.get();
	return 0;
}