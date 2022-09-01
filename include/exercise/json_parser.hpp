
#ifndef AIS2203_EXERCISE2_JSON_PARSER_HPP
#define AIS2203_EXERCISE2_JSON_PARSER_HPP

#include "sensor_data.hpp"

#include <filesystem>
#include <string>

sensor_data_t parse_json(const std::string &jsonStr);

sensor_data_t parse_json(const std::filesystem::path &jsonFile);

#endif//AIS2203_EXERCISE2_JSON_PARSER_HPP
