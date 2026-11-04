#pragma once

#include "api.h"
#include "lemlib/api.hpp"


//controller
extern pros::Controller controller;

//motors & drivetrain
extern pros::MotorGroup left_motor_group;
extern pros::MotorGroup right_motor_group;
extern lemlib::Drivetrain drivetrain;


//sensors
extern pros::Imu imu;
extern pros::Rotation forward_rotation_sensor;
extern lemlib::TrackingWheel forward_tracking_wheel;
extern pros::Rotation sideways_rotation_sensor;
extern lemlib::TrackingWheel sideways_tracking_wheel;
extern lemlib::OdomSensors sensors;


//pid Controllers

extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
//chassis
extern lemlib::Chassis chassis;