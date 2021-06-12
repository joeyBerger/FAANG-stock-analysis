#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class DataImporter {
    public:
        //public method
        std::vector<std::pair<std::string, std::vector<float>>> importData(std::string path);
};

#endif