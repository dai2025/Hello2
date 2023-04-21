#include <iostream>
#include <functional>
#include <string>

static int sub1(void* arg) {
	return (int)(arg); // EXIT_SUCCESS?;
}

void printString(int n, const std::string& s) {
  for (int i = 0; i < n; i++) {
    std::cout << s << "\n";
  }
}

int main() {
  std::function<void(const std::string&)> b = std::bind(printString, 2, std::placeholders::_1);
  b("Hello");
  b("World");
  b("C++");
std::function<int(void*)> func = std::bind(sub1, (NULL), std::placeholders::_1);
  return func();
}
