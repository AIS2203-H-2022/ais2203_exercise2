
#include "exercise/json_parser.hpp"

#include <nlohmann/json.hpp>
#include <fstream>
#include <sstream>

sensor_data_t parse_json(const std::string &jsonStr) {

    sensor_data_t data{};

    nlohmann::json json = nlohmann::json::parse(jsonStr);
    data.imu.is_valid = json["imu"]["is_valid"].get<bool>();
    data.imu.yaw = json["imu"]["yaw"].get<double>();
    data.imu.pitch = json["imu"]["pitch"].get<double>();
    data.imu.roll = json["imu"]["roll"].get<double>();
    data.accelerometer.is_valid = json["accelerometer"]["is_valid"].get<bool>();
    data.accelerometer.x = json["accelerometer"]["x"].get<double>();
    data.accelerometer.y = json["accelerometer"]["y"].get<double>();
    data.accelerometer.z = json["accelerometer"]["z"].get<double>();

    return data;
}

sensor_data_t parse_json(const std::filesystem::path &jsonFile) {
    std::ifstream f(jsonFile);
    std::stringstream strStream;
    strStream << f.rdbuf(); //read the fil
    return parse_json(strStream.str());
}
