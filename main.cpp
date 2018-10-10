#include <iostream>
#include "range.hpp"
int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
	for (auto i : 0_->*10) {
		std::cout << i << std::endl;
		// numbers from 0 to 10 (inclusive) will be printed
	}
}
