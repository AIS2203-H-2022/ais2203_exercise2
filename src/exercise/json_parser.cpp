
#include "exercise/json_parser.hpp"

#include <nlohmann/json.hpp>
#include <fstream>
#include <sstream>

sensor_data_t convert(const nlohmann::json& data) {

    sensor_data_t sensorData{};

    sensorData.imu.is_valid = data["imu"]["is_valid"].get<bool>();
    sensorData.imu.yaw = data["imu"]["yaw"].get<double>();
    sensorData.imu.pitch = data["imu"]["pitch"].get<double>();
    sensorData.imu.roll = data["imu"]["roll"].get<double>();
    sensorData.accelerometer.is_valid = data["accelerometer"]["is_valid"].get<bool>();
    sensorData.accelerometer.x = data["accelerometer"]["x"].get<double>();
    sensorData.accelerometer.y = data["accelerometer"]["y"].get<double>();
    sensorData.accelerometer.z = data["accelerometer"]["z"].get<double>();

    return sensorData;

}

sensor_data_t parse_json(const std::string &jsonStr) {
    nlohmann::json json = nlohmann::json::parse(jsonStr);
    return convert(json);
}

sensor_data_t parse_json(const std::filesystem::path &jsonFile) {
    std::ifstream f(jsonFile);
    nlohmann::json json = nlohmann::json::parse(f);
    return convert(json);
}
