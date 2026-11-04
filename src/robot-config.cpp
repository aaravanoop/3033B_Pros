#include "robot-config.hpp"

//controller

pros::Controller controller(pros::E_CONTROLLER_MASTER);

//Left & right motor groups
pros::MotorGroup left_motor_group({1,2,3});
pros::MotorGroup right_motor_group({4,5,6});

//drivetrain settings

lemlib::Drivetrain drivetrain(&left_motor_group,&right_motor_group,
    10,//10 inch track width
    lemlib::Omniwheel::NEW_275,//using new 2.75" omniwheels
    360,// drivetrain rpm
    2//horizontal drift is 2
);


//inertial sensor(assigned to port 10 as of right now)
pros::Imu imu(10);

//v5 rotational sensor on port 1
pros::Rotation forward_rotation_sensor(1);

//v5 rotational sensor on port 2
pros::Rotation sideways_rotation_sensor(2);

//forward tracking wheel using rotation sensor
lemlib::TrackingWheel forward_tracking_wheel(&forward_rotation_sensor,lemlib::Omniwheel::NEW_275,0,1);

//sideways tracking wheel using rotation sensor
lemlib::TrackingWheel sideways_tracking_wheel(&sideways_rotation_sensor,lemlib::Omniwheel::NEW_275,0,1);

