#include "BinarySearch.cpp"
#include "BreadthFirstSearch.cpp"
#include "DepthFirstSearch.cpp"
#include "SlidingWindowPattern.cpp"

class Tests {
public:
  void test_BinarySearch() {
    BinarySearch();
  }

  void test_BFS() {
    BFS();
  }

  void test_DFS() {
    DFS();
  }

  void test_SlidingWindow() {
    SlidingWindow();
  }
};

int main(int argc, char** argv) {
  Tests tests = Tests();

  // Check through args.Lower, if none run all tests else run flagged tests only.
  // Flags:
  //  BinarySearch = -bs -binarysearch
  //  BFS = -bfs -breadthfirstsearch
  //  DFS = -dfs -depthfirstsearch
  //  SlidingWindow = -sw -slidingwindow

  return 0;
}
