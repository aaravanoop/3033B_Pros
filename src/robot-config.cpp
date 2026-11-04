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

//Odometry sensors setup
lemlib::OdomSensors sensors(&forward_tracking_wheel, nullptr, &sideways_tracking_wheel, nullptr, &imu);

//lateral PID controller
lemlib::ControllerSettings lateral_controller(10,//proportional gain(kp)
    0,//intgrail gain(kI)
    3, //derivative gain (kD)
    3, //anti windup
    1,//small error range, in inches
    100,//small error range timeout, in milliseconds
    3, //large error range, in inches
    500, // large error range timeout, in milliseconds
    20//maximum acceleration(slew)
);

//angular PID controller

lemlib::ControllerSettings angular_contropller(2,//proportional gain(kp)
    0,//intgrail gain(kI)
    10, //derivative gain (kD)
    3, //anti windup
    1,//small error range, in inches
    100,//small error range timeout, in milliseconds
    3, //large error range, in inches
    500, // large error range timeout, in milliseconds
    0//maximum acceleration(slew)
);


//lemlib chassis
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);