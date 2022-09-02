
#include "exercise/json_parser.hpp"

#include <nlohmann/json.hpp>

sensor_data_t parse_json(const std::string &jsonStr) {
    //TODO return a populated sensor_data_t object based on the content of jsonStr
    return {}; // <-- replace me (returns empty sensor_data_t object)
}

sensor_data_t parse_json(const std::filesystem::path &jsonFile) {
    //TODO return a populated sensor_data_t object based on the content of jsonFile
    return {}; // <-- replace me (returns empty sensor_data_t object)
}
