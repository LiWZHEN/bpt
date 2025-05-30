#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <fstream>

constexpr long FILE_UNIT_SIZE = 4096;

template <typename Block>
class file_processor {

  std::fstream file;

public:
  explicit file_processor(const std::string &file_name) {
    bool file_exist = false;
    file.open(file_name);
    if (file.is_open()) {
      file_exist = true;
    }
    file.close();
    if (!file_exist) {
      std::ofstream new_file(file_name);
      new_file.close();
    }
    file.open(file_name);
  }

  ~file_processor() {
    file.close();
  }

  Block ReadBlock(const int index) {
    file.seekg(index * FILE_UNIT_SIZE);
    Block target;
    file.read(reinterpret_cast<char *>(&target), sizeof(target));
    return target;
  }

  long WriteBlock(Block &block) {
    file.seekp(0, std::ios::end);
    long index;
    const auto end = file.tellp();
    if (end % FILE_UNIT_SIZE == 0) {
      index = end / FILE_UNIT_SIZE;
    } else {
      index = end / FILE_UNIT_SIZE + 1;
    }
    file.seekp(index * FILE_UNIT_SIZE);
    file.write(reinterpret_cast<char *>(&block), sizeof(block));
    file.flush();
    return index;
  }

  void WriteBack(Block &block, const int index) {
    file.seekp(index * FILE_UNIT_SIZE);
    file.write(reinterpret_cast<char *>(&block), sizeof(block));
    file.flush();
  }
};

#endif //FILE_PROCESSOR_H
