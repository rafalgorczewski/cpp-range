# cpp-range
Syntactic sugar for range based for loop used with numbers.
### Example
You can now use range based for loop with number ranges. Still, you can only use unsigned long long values because of language limitations.
```cpp
#include <iostream>
#include "range.hpp"
int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
	for (auto i : 0_->*10) {
		std::cout << i << std::endl;
		// numbers from 0 to 10 (inclusive) will be printed
	}
}
```
You can even use your own syntax!
```cpp
for (auto i : 0_︻デ一->*10) {
		std::cout << i << std::endl;
}
```
