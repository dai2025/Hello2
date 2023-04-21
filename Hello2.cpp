#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <vector>

static int sub1(void* arg) {
	return (int)(arg); // EXIT_SUCCESS?;
}

static int sub2(int argc, char* argv) {
/*
std::vector<std::string> arg(argv, argv+argc);
std::ifstream inputFile;
std::ofstream outputFile;
inputFile.open("input.txt");
if (inputFile.fail()) {
std::cout << "Error opening input file.\n";
return 1;
}
outputFile.open("output.txt");
if (outputFile.fail()) {
std::cout << "Error opening output file.\n";
return 1;
}
std::string line;
while (getline(inputFile, line)) {
outputFile << line << "\n";
std::cout << line << "\n";
}
for (const auto c: arg)
outputFile << c << "\n";
inputFile.close();
outputFile.close();
std::cout << "Done.\n";
*/
	return (int)(argc); // EXIT;
}

void printString(int n, const std::string& s) {
  for (int i = 0; i < n; i++) {
    std::cout << s << "\n";
  }
}

int main() {
  std::function<void(const std::string&)> b = std::bind(printString, 1, std::placeholders::_1);
  b("Hello");
  b("World");
std::function<int(void*)> func = std::bind(sub1, (NULL), std::placeholders::_1);
  return func();
}

