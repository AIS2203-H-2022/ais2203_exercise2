
#ifndef AIS2203_EXERCISE2_SENSOR_DATA_HPP
#define AIS2203_EXERCISE2_SENSOR_DATA_HPP

struct sensor_data_t
{
    struct imu_t {
        bool is_valid;
        double roll;
        double pitch;
        double yaw;
    };

    struct accelerometer_t {
        bool is_valid;
        double x;
        double y;
        double z;
    };

    imu_t imu;
    accelerometer_t accelerometer;
};

#endif//AIS2203_EXERCISE2_SENSOR_DATA_HPP
