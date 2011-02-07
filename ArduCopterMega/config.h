// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: t -*-
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
//  DO NOT EDIT this file to adjust your configuration.  Create your own
//  APM_Config.h and use APM_Config.h.example as a reference.
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
///
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Default and automatic configuration details.
//
// Notes for maintainers:
//
// - Try to keep this file organised in the same order as APM_Config.h.example
//

#include "defines.h"

///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
/// 
#include "APM_Config.h"  // <== THIS INCLUDE, DO NOT EDIT IT
///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
/// 

// Just so that it's completely clear...
#define ENABLED			1
#define DISABLED		0

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// HARDWARE CONFIGURATION AND CONNECTIONS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// ENABLE_HIL
// Hardware in the loop output
//
#ifndef ENABLE_HIL
# define ENABLE_HIL		DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// GPS_PROTOCOL
//
#ifndef GPS_PROTOCOL
# error XXX
# error XXX You must define GPS_PROTOCOL in APM_Config.h
# error XXX
#endif

// The X-Plane GCS requires the IMU GPS configuration
#if (ENABLE_HIL == ENABLED) && (GPS_PROTOCOL != GPS_PROTOCOL_IMU)
# error Must select GPS_PROTOCOL_IMU when configuring for X-Plane or Flight Gear HIL
#endif


//////////////////////////////////////////////////////////////////////////////
// FRAME_CONFIG
// 
#ifndef FRAME_CONFIG
# define FRAME_CONFIG		PLUS_FRAME
#endif


//////////////////////////////////////////////////////////////////////////////
// GCS_PROTOCOL
// GCS_PORT
//
#ifndef GCS_PROTOCOL
# define GCS_PROTOCOL			GCS_PROTOCOL_STANDARD
#endif

#ifndef GCS_PORT
# if (GCS_PROTOCOL == GCS_PROTOCOL_STANDARD) || (GCS_PROTOCOL == GCS_PROTOCOL_LEGACY)
#  define GCS_PORT				3
# else
#  define GCS_PORT				0
# endif
#endif


//////////////////////////////////////////////////////////////////////////////
// Serial port speeds.
//
#ifndef SERIAL0_BAUD
# define SERIAL0_BAUD			38400
#endif
#ifndef SERIAL3_BAUD
# define SERIAL3_BAUD			115200
#endif


//////////////////////////////////////////////////////////////////////////////
// Battery monitoring
//
#ifndef BATTERY_EVENT
# define BATTERY_EVENT			DISABLED
#endif
#ifndef BATTERY_TYPE
# define BATTERY_TYPE			0
#endif
#ifndef LOW_VOLTAGE
# define LOW_VOLTAGE			9.6
#endif
#ifndef VOLT_DIV_RATIO
# define VOLT_DIV_RATIO			3.0
#endif
#ifndef CURR_VOLT_DIV_RATIO
# define CURR_VOLT_DIV_RATIO	15.7
#endif
#ifndef CURR_AMP_DIV_RATIO
# define CURR_AMP_DIV_RATIO		30.35
#endif


//////////////////////////////////////////////////////////////////////////////
// INPUT_VOLTAGE
//
#ifndef INPUT_VOLTAGE
# define INPUT_VOLTAGE			5.0
#endif


//////////////////////////////////////////////////////////////////////////////
//  MAGNETOMETER
#ifndef MAGORIENTATION
# define MAGORIENTATION			APM_COMPASS_COMPONENTS_UP_PINS_FORWARD
#endif

// run the CLI tool to get this value
#ifndef MAGOFFSET
# define MAGOFFSET	0,0,0
#endif

// Declination is a correction factor between North Pole and real magnetic North. This is different on every location
// IF you want to use really accurate headholding and future navigation features, you should update this
// You can check Declination to your location from http://www.magnetic-declination.com/
#ifndef DECLINATION
# define DECLINATION	0
#endif





//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// RADIO CONFIGURATION
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// FLIGHT_MODE
// FLIGHT_MODE_CHANNEL
//
#ifndef FLIGHT_MODE_CHANNEL
# define FLIGHT_MODE_CHANNEL	CH_5
#endif
#if (FLIGHT_MODE_CHANNEL != CH_5) && (FLIGHT_MODE_CHANNEL != CH_6) && (FLIGHT_MODE_CHANNEL != CH_7) && (FLIGHT_MODE_CHANNEL != CH_8)
# error XXX
# error XXX You must set FLIGHT_MODE_CHANNEL to 5, 6, 7 or 8
# error XXX
#endif

#if !defined(FLIGHT_MODE_1)
# define FLIGHT_MODE_1			STABILIZE
#endif
#if !defined(FLIGHT_MODE_2)
# define FLIGHT_MODE_2			STABILIZE
#endif
#if !defined(FLIGHT_MODE_3)
# define FLIGHT_MODE_3			STABILIZE
#endif
#if !defined(FLIGHT_MODE_4)
# define FLIGHT_MODE_4			STABILIZE
#endif
#if !defined(FLIGHT_MODE_5)
# define FLIGHT_MODE_5			STABILIZE
#endif
#if !defined(FLIGHT_MODE_6)
# define FLIGHT_MODE_6			STABILIZE
#endif


//////////////////////////////////////////////////////////////////////////////
// THROTTLE_FAILSAFE
// THROTTLE_FS_VALUE
// THROTTLE_FAILSAFE_ACTION
//
#ifndef THROTTLE_FAILSAFE
# define THROTTLE_FAILSAFE		DISABLED
#endif
#ifndef THROTTE_FS_VALUE
# define THROTTLE_FS_VALUE		975
#endif
#ifndef THROTTLE_FAILSAFE_ACTION
# define THROTTLE_FAILSAFE_ACTION		2
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// STARTUP BEHAVIOUR
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// GROUND_START_DELAY
//
#ifndef GROUND_START_DELAY
# define GROUND_START_DELAY		0
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// FLIGHT AND NAVIGATION CONTROL
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// ACRO Rate Control

#ifndef ACRO_RATE_ROLL_P
# define ACRO_RATE_ROLL_P         .190
#endif
#ifndef ACRO_RATE_ROLL_I
# define ACRO_RATE_ROLL_I         0.0
#endif
#ifndef ACRO_RATE_ROLL_D
# define ACRO_RATE_ROLL_D         0.0
#endif
#ifndef ACRO_RATE_ROLL_IMAX
# define ACRO_RATE_ROLL_IMAX	 20
#endif

#ifndef ACRO_RATE_PITCH_P
# define ACRO_RATE_PITCH_P         .190
#endif
#ifndef ACRO_RATE_PITCH_I
# define ACRO_RATE_PITCH_I         0.0
#endif
#ifndef ACRO_RATE_PITCH_D
# define ACRO_RATE_PITCH_D         0.0
#endif
#ifndef ACRO_RATE_PITCH_IMAX
# define ACRO_RATE_PITCH_IMAX   20 
#endif

#ifndef ACRO_RATE_YAW_P
# define ACRO_RATE_YAW_P         .07
#endif
#ifndef ACRO_RATE_YAW_I
# define ACRO_RATE_YAW_I         0.0
#endif
#ifndef ACRO_RATE_YAW_D
# define ACRO_RATE_YAW_D         0.0
#endif
#ifndef ACRO_RATE_YAW_IMAX
# define ACRO_RATE_YAW_IMAX   0
#endif

#ifndef ACRO_RATE_TRIGGER
# define ACRO_RATE_TRIGGER   100
#endif



//////////////////////////////////////////////////////////////////////////////
// STABILZE Angle Control
//
#ifndef STABILIZE_ROLL_P
# define STABILIZE_ROLL_P 		0.6
#endif
#ifndef STABILIZE_ROLL_I
# define STABILIZE_ROLL_I 		0.0
#endif
#ifndef STABILIZE_ROLL_D
# define STABILIZE_ROLL_D 		0.0
#endif
#ifndef STABILIZE_ROLL_IMAX
# define STABILIZE_ROLL_IMAX 	3
#endif

#ifndef STABILIZE_PITCH_P
# define STABILIZE_PITCH_P		0.6
#endif
#ifndef STABILIZE_PITCH_I
# define STABILIZE_PITCH_I		0.0
#endif
#ifndef STABILIZE_PITCH_D
# define STABILIZE_PITCH_D		0.0
#endif
#ifndef STABILIZE_PITCH_IMAX
# define STABILIZE_PITCH_IMAX	3
#endif

// STABILZE RATE Control
//
#ifndef STABILIZE_DAMPENER
# define STABILIZE_DAMPENER		0.135
#endif


//////////////////////////////////////////////////////////////////////////////
// YAW Control
//
#ifndef  YAW_P
# define YAW_P					0.5
#endif
#ifndef  YAW_I
# define YAW_I					0.0
#endif
#ifndef  YAW_D
# define YAW_D					0.0
#endif
#ifndef  YAW_IMAX
# define YAW_IMAX				1
#endif

// STABILZE YAW Control
//
#ifndef HOLD_YAW_DAMPENER
# define HOLD_YAW_DAMPENER		0.175
#endif

//////////////////////////////////////////////////////////////////////////////
// Throttle control
//
#ifndef THROTTLE_MIN
# define THROTTLE_MIN			0
#endif
#ifndef THROTTLE_CRUISE
# define THROTTLE_CRUISE		250
#endif
#ifndef THROTTLE_MAX
# define THROTTLE_MAX			1000
#endif


//////////////////////////////////////////////////////////////////////////////
// Autopilot control limits
//
// how much to we pitch towards the target
#ifndef PITCH_MAX
# define PITCH_MAX				40
#endif


//////////////////////////////////////////////////////////////////////////////
// Navigation control gains
//
#ifndef NAV_P
# define NAV_P					2.0
#endif
#ifndef NAV_I
# define NAV_I					0.00
#endif
#ifndef NAV_D
# define NAV_D					0.00
#endif
#ifndef NAV_IMAX
# define NAV_IMAX				250
#endif


//////////////////////////////////////////////////////////////////////////////
// Throttle control gains
//
#ifndef THROTTLE_BARO_P
# define THROTTLE_BARO_P		0.12
#endif
#ifndef THROTTLE_BARO_I
# define THROTTLE_BARO_I		0.05
#endif
#ifndef THROTTLE_BARO_D
# define THROTTLE_BARO_D		0.06
#endif
#ifndef THROTTLE_BARO_IMAX
# define THROTTLE_BARO_IMAX		100
#endif

#ifndef THROTTLE_SONAR_P
# define THROTTLE_SONAR_P		.8
#endif
#ifndef THROTTLE_SONAR_I
# define THROTTLE_SONAR_I		0.3
#endif
#ifndef THROTTLE_SONAR_D
# define THROTTLE_SONAR_D		0.7
#endif
#ifndef THROTTLE_SONAR_IMAX
# define THROTTLE_SONAR_IMAX	300
#endif


//////////////////////////////////////////////////////////////////////////////
// Crosstrack compensation
//
#ifndef XTRACK_GAIN
# define XTRACK_GAIN          0.01
#endif
#ifndef XTRACK_ENTRY_ANGLE
# define XTRACK_ENTRY_ANGLE   30
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// DEBUGGING
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// DEBUG_SUBSYSTEM
//
#ifndef DEBUG_SUBSYSTEM
# define DEBUG_SUBSYSTEM		0
#endif


//////////////////////////////////////////////////////////////////////////////
// DEBUG_LEVEL
//
#ifndef DEBUG_LEVEL
# define DEBUG_LEVEL SEVERITY_LOW
#endif


//////////////////////////////////////////////////////////////////////////////
// Dataflash logging control
//
#ifndef LOG_ATTITUDE_FAST
# define LOG_ATTITUDE_FAST		DISABLED
#endif
#ifndef LOG_ATTITUDE_MED
# define LOG_ATTITUDE_MED 		ENABLED
#endif
#ifndef LOG_GPS
# define LOG_GPS 				ENABLED
#endif
#ifndef LOG_PM
# define LOG_PM 				ENABLED
#endif
#ifndef LOG_CTUN
# define LOG_CTUN				DISABLED
#endif
#ifndef LOG_NTUN
# define LOG_NTUN				DISABLED
#endif
#ifndef LOG_MODE
# define LOG_MODE				ENABLED
#endif
#ifndef LOG_RAW
# define LOG_RAW				DISABLED
#endif
#ifndef LOG_CMD
# define LOG_CMD				ENABLED
#endif
#ifndef LOG_CURRENT
# define LOG_CURRENT			DISABLED
#endif



