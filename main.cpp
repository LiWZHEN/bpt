#include <iostream>
#include "b_plus_tree.h"

int main() {
  sjtu::bpt<int *> bpt("map_info.txt", "data.txt");
  int group[2];
  group[0] = 0;
  group[1] = 1;
  bpt.Insert("first", group);
  bpt.Insert("second", "2");
  auto ans = bpt.Find("first");
  for (const auto &it : ans) {
    std::cout << it << std::endl;
  }
  bpt.Delete("first", "1");
  ans = bpt.Find("first");
  for (const auto &it : ans) {
    std::cout << it << std::endl;
  }
  std::cout << bpt.Size();
  return 0;
}