#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>

class DataLoader {
public:
    DataLoader(const std::string& data_path);
    std::vector<std::string> load_data(); // Changed from vector<unordered_map>
private:
    std::string data_path;
};

#endif // DATALOADER_H
