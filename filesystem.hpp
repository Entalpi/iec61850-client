#ifndef _FILESYSTEM_HPP_
#define _FILESYSTEM_HPP_

#include "measurement.hpp"
#include <fstream>

#ifdef __LINUX__
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <errno.h>
  #include <stdio.h>
#elif
  #error OS not supported
#endif

namespace FS {
  template<typename T>
  bool save_data(std::vector<Measurement<T>> &values, std::string file_path) {
    std::ofstream file(file_path);
    if (!file.good()) { return false; }
    for (auto &value : values) {
      file << value.timestamp << ";" << value.value << std::endl;
    }
    return true;
  }
}

#endif // _FILESYSTEM_HPP_
