#include "data_importer.h"

std::vector<std::pair<std::string, std::vector<float>>> DataImporter::importData(std::string path) {
    //setup result object
    std::string line;
    const int HEADER_SIZE = 7;
    std::string column_headers[HEADER_SIZE];
    for (int i = 0; i < HEADER_SIZE; i++) column_headers[i] = "";
    std::ifstream filestream(path);    
    std::vector<std::pair<std::string, std::vector<float>>> result;
    
    //handle error if file not found
    if(!filestream.is_open()) throw std::runtime_error("Could not open file: " + path);
    else {
        bool pairCreated = false;
        while (std::getline(filestream, line)) {
            //replace charcters for ease of use
            std::replace(line.begin(), line.end(), ' ', '_');
            std::replace(line.begin(), line.end(), ',', ' ');
            std::istringstream linestream(line);
            //assign file text to array
            while (linestream >> column_headers[0] >> column_headers[1] >> column_headers[2] >> column_headers[3] >> column_headers[4] >> column_headers[5] >> column_headers[6]) {
                //if pair not created, initialize pair, otherwise, push data
                if (!pairCreated) {
                    for (int i = 0; i < HEADER_SIZE; i ++) result.push_back({column_headers[i], std::vector<float> {}});
                    pairCreated = true;
                } else for (int i = 0; i < HEADER_SIZE; i ++) result.at(i).second.push_back(stof(column_headers[i]));
            }
        }
    }
    return result;
}