#include <iostream>
#include "b_plus_tree.h"

int main() {
  sjtu::bpt<int> bpt("map_file.txt", "data_file.txt");

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string command;
    std::cin >> command;
    if (command == "insert") {
      std::string index;
      int value;
      std::cin >> index >> value;
      bpt.Insert(index, value);
    } else if (command == "delete") {
      std::string index;
      int value;
      std::cin >> index >> value;
      bpt.Delete(index, value);
    } else if (command == "find") {
      std::string index;
      std::cin >> index;
      const auto ans = bpt.Find(index);
      for (const auto it : ans) {
        std::cout << it << ' ';
      }
      if (ans.empty()) {
        std::cout << "null";
      }
      std::cout << '\n';
    }
  }
  return 0;
}