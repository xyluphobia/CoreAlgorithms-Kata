#include <filesystem>
#include <fstream>

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
  ofstream binarySearchFile(attemptDirectory + "/BinarySearch.cpp");
  ofstream depthFirstSearch(attemptDirectory + "/DepthFirstSearch.cpp");
  ofstream breadthFirstSearch(attemptDirectory + "/BreadthFirstSearch.cpp");
  ofstream slidingWindowPattern(attemptDirectory + "/SlidingWindowPattern.cpp");
  
  if (binarySearchFile.is_open()) {
    binarySearchFile << "#include<iostream>\n\nint BinarySearch() {\n\t\n\treturn 0;\n}";
  }
  if (depthFirstSearch.is_open()) {
    depthFirstSearch << "#include<iostream>\n\nint DFS() {\n\t\n\treturn 0;\n}";
  }
  if (breadthFirstSearch.is_open()) {
    breadthFirstSearch << "#include<iostream>\n\nint BFS() {\n\t\n\treturn 0;\n}";
  }
  if (slidingWindowPattern.is_open()) {
    slidingWindowPattern << "#include<iostream>\n\nint SlidingWindow() {\n\t\n\treturn 0;\n}";
  }
  
  binarySearchFile.close();
  depthFirstSearch.close();
  breadthFirstSearch.close();
  slidingWindowPattern.close();

  // Add test funcions here so that they are run by compiling and running test file
  // They should have the option to run only one test using a flag. e.g. -binarysearch
  // This file will be created in src/tests.cpp & copied into new directories.
  fs::copy("tests.cpp", attemptDirectory+ "/tests.cpp");
}
