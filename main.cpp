#include <filesystem>
#include <ctime>

#include "src/Utils.hpp"

using namespace std;
namespace fs = std::filesystem;

int main (int argc, char** argv) {
  
  // Command to build: {month}/Attempt_{X}/{algorithm}.cpp
  time_t now = time(nullptr);
  tm* local_time = localtime(&now);
  int current_month = local_time->tm_mon;
  string monthString = GetMonthString(current_month);

  if (!fs::exists(monthString)) {
    fs::create_directory(monthString);
  }

  // Build template cpp files
  BuildFiles(monthString);


  // TODO: Command to run tests: test {algorithm}
  

  /*for (int i = 1; i < argc; i++) {
    cout << argv[i] << "\n";
  }*/

  return 0;
}
