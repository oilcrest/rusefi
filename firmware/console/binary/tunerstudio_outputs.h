/*
 * @file	tunerstudio_outputs.h
 * @brief	Tuner Studio connectivity configuration
 *
 * In this file the configuration of TunerStudio is defined
 *
 * @date Oct 22, 2013
 * @author Andrey Belomutskiy, (c) 2012-2020
 */

#pragma once

#include "rusefi_types.h"
#include "scaled_channel.h"
#include "tunerstudio_debug_struct.h"
#include "ts_outputs_generated.h"

enum class TsCalMode : uint8_t {
	None = 0,
	Tps1Max = 1,
	Tps1Min = 2,
	EtbKp = 3,
	EtbKi = 4,
	EtbKd = 5,
	Tps1SecondaryMax = 6,
	Tps1SecondaryMin = 7,
	Tps2Max = 8,
	Tps2Min = 9,
	Tps2SecondaryMax = 10,
	Tps2SecondaryMin = 11,
};

/**
 * todo https://github.com/rusefi/rusefi/issues/197
 * At the moment rusEFI does NOT have any code generation around TS output channels, three locations have to be changed manually
 * 1) this TunerStudioOutputChannels firmware version of the structure
 * 2) '[OutputChannels]' block in rusefi.input
 * 3) com.rusefi.core.Sensor enum in rusEFI console source code
 *
 * status update: there is progress, a portion of this struct is now generated! we inherit from generated
 * ts_outputs_s and eventually the whole thing would be generated
 *
 */
struct TunerStudioOutputChannels : ts_outputs_s {
	/* see also [OutputChannels] in rusefi.input */

	scaled_channel<uint16_t, 100> ignitionLoad; // 136

	// we want a hash of engineMake+engineCode+vehicleName in the log file in order to match TS logs to rusEFI Online tune
	scaled_channel<uint16_t> engineMakeCodeNameCrc16; // 138
	// Errors
	scaled_channel<uint32_t> totalTriggerErrorCounter; // 140
	int orderingErrorCounter; // 144
	scaled_channel<uint16_t> warningCounter; // 148
	scaled_channel<uint16_t> lastErrorCode; // 150
	int16_t recentErrorCodes[8]; // 152-166

	// Debug
	scaled_channel<float> debugFloatField1; // 168
	scaled_channel<float> debugFloatField2;
	scaled_channel<float> debugFloatField3;
	scaled_channel<float> debugFloatField4;
	scaled_channel<float> debugFloatField5;
	scaled_channel<float> debugFloatField6;
	scaled_channel<float> debugFloatField7;
	scaled_channel<uint32_t> debugIntField1;
	scaled_channel<uint32_t> debugIntField2;
	scaled_channel<uint32_t> debugIntField3;
	scaled_channel<uint16_t> debugIntField4;
	scaled_channel<uint16_t> debugIntField5; // 210

	// accelerometer
	scaled_percent accelerationX; // 212
	scaled_percent accelerationY; // 214

	// EGT
	uint16_t egtValues[EGT_CHANNEL_COUNT] ; // 216

	scaled_percent throttle2Position;    // 232

	scaled_voltage rawTps1Primary;		// 234
	scaled_voltage rawPpsPrimary;		// 236
	scaled_voltage rawClt;				// 238
	scaled_voltage rawIat;				// 240
	scaled_voltage rawOilPressure;		// 242

	scaled_channel<uint16_t> tuneCrc16; // 244

	scaled_channel<uint8_t> unusedAt246;

	scaled_channel<uint8_t> tcuCurrentGear; // 247

	scaled_voltage rawPpsSecondary;		// 248

	scaled_channel<int8_t> knockLevels[12];		// 250

	scaled_channel<uint8_t> tcuDesiredGear; // 262
	scaled_channel<uint8_t, 2> flexPercent;		// 263

	scaled_voltage rawIdlePositionSensor;	// 264
	scaled_voltage rawWastegatePositionSensor;	// 266

	scaled_percent wastegatePosition;	// 268
	scaled_percent idlePositionSensor;	// 270

	scaled_voltage rawLowFuelPressure; // 272
	scaled_voltage rawHighFuelPressure; // 274

	scaled_pressure lowFuelPressure;	// 276
	scaled_high_pressure highFuelPressure;	// 278

	scaled_lambda targetLambda; // 280
	scaled_afr airFuelRatio; // 282

	scaled_ms VssAcceleration; //284

	scaled_lambda lambda2; // 286
	scaled_afr airFuelRatio2; // 288

	scaled_angle vvtPositionB1E; // 290
	scaled_angle vvtPositionB2I; // 292
	scaled_angle vvtPositionB2E; // 294

	scaled_percent fuelTrim[2];	// 296 & 298

	scaled_voltage rawTps1Secondary;	// 300
	scaled_voltage rawTps2Primary;		// 302
	scaled_voltage rawTps2Secondary;	// 304

	scaled_channel<uint16_t> knockCount;// 306

	scaled_percent accelerationZ; // 308
	scaled_percent accelerationRoll; // 310
	scaled_percent accelerationYaw; // 312

	scaled_channel<int8_t> vvtTargets[4]; // 314
	scaled_channel<uint16_t> turboSpeed; // 318

	uint8_t unusedAtTheEnd[18]; // we have some unused bytes to allow compatible TS changes

	// Temporary - will remove soon
	TsDebugChannels* getDebugChannels() {
		return reinterpret_cast<TsDebugChannels*>(&debugFloatField1);
	}

	/* see also [OutputChannels] in rusefi.input */
	/* see also TS_OUTPUT_SIZE in rusefi_config.txt */
};

extern TunerStudioOutputChannels tsOutputChannels;
