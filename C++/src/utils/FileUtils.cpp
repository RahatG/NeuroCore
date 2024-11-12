#include "FileUtils.h"
#include <sys/stat.h>

bool FileUtils::file_exists(const std::string& path) {
    struct stat buffer;
    return (stat (path.c_str(), &buffer) == 0);
}
