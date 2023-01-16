// this section was generated automatically by rusEFI tool ConfigDefinition.jar based on (unknown script) controllers/actuators/boost_control.txt Mon Jan 16 20:36:57 UTC 2023
// by class com.rusefi.output.CHeaderConsumer
// begin
#pragma once
#include "rusefi_types.h"
// start of boost_control_s
struct boost_control_s {
	/**
	offset 0 bit 0 */
	bool isTpsInvalid : 1 {};
	/**
	offset 0 bit 1 */
	bool m_shouldResetPid : 1 {};
	/**
	offset 0 bit 2 */
	bool isBelowClosedLoopThreshold : 1 {};
	/**
	offset 0 bit 3 */
	bool isNotClosedLoop : 1 {};
	/**
	offset 0 bit 4 */
	bool isZeroRpm : 1 {};
	/**
	offset 0 bit 5 */
	bool hasInitBoost : 1 {};
	/**
	offset 0 bit 6 */
	bool unusedBit_6_6 : 1 {};
	/**
	offset 0 bit 7 */
	bool unusedBit_6_7 : 1 {};
	/**
	offset 0 bit 8 */
	bool unusedBit_6_8 : 1 {};
	/**
	offset 0 bit 9 */
	bool unusedBit_6_9 : 1 {};
	/**
	offset 0 bit 10 */
	bool unusedBit_6_10 : 1 {};
	/**
	offset 0 bit 11 */
	bool unusedBit_6_11 : 1 {};
	/**
	offset 0 bit 12 */
	bool unusedBit_6_12 : 1 {};
	/**
	offset 0 bit 13 */
	bool unusedBit_6_13 : 1 {};
	/**
	offset 0 bit 14 */
	bool unusedBit_6_14 : 1 {};
	/**
	offset 0 bit 15 */
	bool unusedBit_6_15 : 1 {};
	/**
	offset 0 bit 16 */
	bool unusedBit_6_16 : 1 {};
	/**
	offset 0 bit 17 */
	bool unusedBit_6_17 : 1 {};
	/**
	offset 0 bit 18 */
	bool unusedBit_6_18 : 1 {};
	/**
	offset 0 bit 19 */
	bool unusedBit_6_19 : 1 {};
	/**
	offset 0 bit 20 */
	bool unusedBit_6_20 : 1 {};
	/**
	offset 0 bit 21 */
	bool unusedBit_6_21 : 1 {};
	/**
	offset 0 bit 22 */
	bool unusedBit_6_22 : 1 {};
	/**
	offset 0 bit 23 */
	bool unusedBit_6_23 : 1 {};
	/**
	offset 0 bit 24 */
	bool unusedBit_6_24 : 1 {};
	/**
	offset 0 bit 25 */
	bool unusedBit_6_25 : 1 {};
	/**
	offset 0 bit 26 */
	bool unusedBit_6_26 : 1 {};
	/**
	offset 0 bit 27 */
	bool unusedBit_6_27 : 1 {};
	/**
	offset 0 bit 28 */
	bool unusedBit_6_28 : 1 {};
	/**
	offset 0 bit 29 */
	bool unusedBit_6_29 : 1 {};
	/**
	offset 0 bit 30 */
	bool unusedBit_6_30 : 1 {};
	/**
	offset 0 bit 31 */
	bool unusedBit_6_31 : 1 {};
	/**
	 * offset 4
	 */
	float luaTargetAdd = (float)0;
	/**
	 * offset 8
	 */
	float luaTargetMult = (float)0;
	/**
	 * offset 12
	 */
	float openLoopPart = (float)0;
	/**
	 * offset 16
	 */
	float luaOpenLoopAdd = (float)0;
	/**
	 * @@GAUGE_NAME_BOOST_CLOSED_LOOP@@
	%
	 * offset 20
	 */
	scaled_channel<int8_t, 2, 1> boostControllerClosedLoopPart = (int8_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 21
	 */
	uint8_t alignmentFill_at_21[1];
	/**
	 * @@GAUGE_NAME_BOOST_TARGET@@
	kPa
	 * offset 22
	 */
	scaled_channel<int16_t, 30, 1> boostControlTarget = (int16_t)0;
};
static_assert(sizeof(boost_control_s) == 24);

// end
// this section was generated automatically by rusEFI tool ConfigDefinition.jar based on (unknown script) controllers/actuators/boost_control.txt Mon Jan 16 20:36:57 UTC 2023
