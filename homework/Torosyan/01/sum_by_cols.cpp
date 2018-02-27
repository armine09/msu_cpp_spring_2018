#include <iostream>
#include <chrono>
#include <cstdint>

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};

const int n = 10000;

int main() {
	int **A = new int*[n];
	for (int i = 0; i < n; ++i) {
		A[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			A[i][j] = i + j;
		}
	}

	{
		Timer t;
		int64_t sum = 0;
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; ++i) {
			sum += A[i][j];
			}
		}
		std::cout << "Sum of array elements is : " << sum << std::endl;
	}
	for (int i = 0; i < n; ++i) {
		delete[] A[i];
	}
	delete[] A;
}
