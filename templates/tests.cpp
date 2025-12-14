#include <cassert>

#include "BinarySearch.cpp"
#include "BreadthFirstSearch.cpp"
#include "DepthFirstSearch.cpp"
#include "SlidingWindowPattern.cpp"

class Tests {
public:
  void test_BinarySearch() {
    assert(BinarySearch(new int[]{1,2,3,4,5}, 9) == -1);
    assert(BinarySearch(new int[]{1,2,3,4,5}, 3) == -1);
    assert(BinarySearch(new int[]{1,2,3,4,5}, 1) == -1);
    assert(BinarySearch(new int[]{1,2,3,4,5}, 5) == -1);
    assert(BinarySearch(new int[]{1,2,3,4,5}, -1) == -1);
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
