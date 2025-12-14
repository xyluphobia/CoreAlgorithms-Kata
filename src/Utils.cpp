#include <filesystem>

#include "Utils.hpp"

using namespace std;
namespace fs = std::filesystem;

string GetMonthString(int i) {
  switch (i) {
    case 0:
      return "January";
    case 1:
      return "Febuary";
    case 2:
      return "March";
    case 3:
      return "April";
    case 4:
      return "May";
    case 5:
      return "June";
    case 6:
      return "July";
    case 7:
      return "August";
    case 8:
      return "September";
    case 9:
      return "October";
    case 10:
      return "November";
    case 11:
      return "December";

  }
  return "";
}

string GetAttemptDirectory(string monthString) {
  bool foundAttemptCount = false;
  int currentCount = 0;
  while (!foundAttemptCount) {
    string buildPath = monthString + "/Attempt_" + to_string(currentCount);
    if (!fs::exists(buildPath)) {
      foundAttemptCount = true;
      fs::create_directory(buildPath);
      return buildPath;
    }
    else {
      currentCount++;
    }
  }
  return monthString + "/Error";
}

void BuildFiles(string monthString) { 
  string attemptDirectory = GetAttemptDirectory(monthString);

  fs::copy("templates/BinarySearch.cpp", attemptDirectory+ "/BinarySearch.cpp");
  fs::copy("templates/DepthFirstSearch.cpp", attemptDirectory+ "/DepthFirstSearch.cpp");
  fs::copy("templates/BreadthFirstSearch.cpp", attemptDirectory+ "/BreadthFirstSearch.cpp");
  fs::copy("templates/SlidingWindowPattern.cpp", attemptDirectory+ "/SlidingWindowPattern.cpp");
  
  fs::copy("templates/tests.cpp", attemptDirectory+ "/tests.cpp");
}

