
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <filesystem>

#include "exercise/json_parser.hpp"


TEST_CASE("Test parse_json JSON file") {

    const auto jsonFile = std::filesystem::path(DATA_DIR) / "sensor_data.json";
    const auto data = parse_json(jsonFile);

    CHECK(data.imu.is_valid);
    CHECK(data.imu.roll == Approx(0.14));
    CHECK(data.imu.pitch == Approx(0.013));
    CHECK(data.imu.yaw == Approx(-5.68));

    CHECK(data.accelerometer.is_valid);
    CHECK(data.accelerometer.x == Approx(0));
    CHECK(data.accelerometer.y == Approx(-0.01));
    CHECK(data.accelerometer.z == Approx(-0.23));
}

TEST_CASE("Test parse_json JSON string") {

    const std::string json = R"(
        {
          "imu": {
            "is_valid": true,
            "roll": 0.12,
            "pitch": -0.024,
            "yaw": -4.32
          },
          "accelerometer": {
            "is_valid": true,
            "x": -0.001,
            "y": -0.11,
            "z": 0.33
          }
        }
    )";
    const auto data = parse_json(json);

    CHECK(data.imu.is_valid);
    CHECK(data.imu.roll == Approx(0.12));
    CHECK(data.imu.pitch == Approx(-0.024));
    CHECK(data.imu.yaw == Approx(-4.32));

    CHECK(data.accelerometer.is_valid);
    CHECK(data.accelerometer.x == Approx(-0.001));
    CHECK(data.accelerometer.y == Approx(-0.11));
    CHECK(data.accelerometer.z == Approx(0.33));
}
