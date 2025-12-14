#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
using std::string;

string GetMonthString(int i);
string GetAttemptDirectory(string monthString);
void BuildFiles(string monthString);

#endif
