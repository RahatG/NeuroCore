#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

class FileUtils {
public:
    static bool file_exists(const std::string& path);
};

#endif // FILEUTILS_H
