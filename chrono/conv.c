#include <chrono>

using namespace std::chrono;

milliseconds f(seconds x) {
 return x;
}

int64_t g(int64_t x) {
	return 1000*x;
}
