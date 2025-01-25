/*
	SlimeVR Code is placed under the MIT license
	Copyright (c) 2022 SlimeVR Contributors

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#ifndef DEFINES_SENSITIVITY_H
#define DEFINES_SENSITIVITY_H

// ==========================
// Sensitivity calibration
// Only for: BMI160
// ==========================

// This type of calibration attempts to reduce "extra degrees measures",
// useful if you do 360 spins

// Trackers are identified by sensor id and MAC address of the device,
// which is displayed in serial when you upload firmware

// Number of spins determines calibration accuracy

// 1. Put the axis you want to calibrate vertically
// 2. Put the tracker into an orientation that you can repeat later
// 3. Do a full reset, rotation must now be 0 0 0
// 4. Spin the tracker clockwise <.spins> times around the axis
// 5. Put the tracker back into the reset position
// 6. Write down the resulting Y (yaw) value into the table below
// Reflash, do the same rotation and check if the resulting angle is now 0

#define SENSORID_PRIMARY 0
#define SENSORID_AUX 1
struct SensitivityOffsetXYZ {
	const char* mac;
	unsigned char sensorId;
	double spins;
	double x;
	double y;
	double z;
};
const SensitivityOffsetXYZ sensitivityOffsets[] = {
    // example values
    { .mac = "80:64:6F:AE:0C:06", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = 46, .y = 26, .z = 38 }, // Left thigh
    { .mac = "80:64:6F:B0:27:27", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = 14, .y = 17, .z = 4 }, // Right thigh
    { .mac = "80:64:6F:AD:EF:A0", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = 36, .y = 29, .z = 30 }, // Right arm
    { .mac = "80:64:6F:B0:24:98", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = -11, .y = -13, .z = -21 }, // Left arm
    { .mac = "80:64:6F:AD:EE:77", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = 14, .y = 26, .z = 19 }, // Chest
    { .mac = "80:64:6F:A7:1C:CF", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = 47, .y = 23, .z = 30 }, // Hip
    { .mac = "80:64:6F:A7:17:E8", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = 0, .y = -5, .z = -19 }, // Right foot
    { .mac = "80:64:6F:A7:17:E8", .sensorId = SENSORID_AUX, .spins = 10, .x = 16, .y = 15, .z = 7 }, // Right ankle
    { .mac = "80:64:6F:AD:EE:F2", .sensorId = SENSORID_PRIMARY, .spins = 10, .x = -31, .y = -4, .z = -9 }, // Left foot
    { .mac = "80:64:6F:AD:EE:F2", .sensorId = SENSORID_AUX, .spins = 10, .x = 46, .y = -13, .z = -2 }, // Left ankle
};

#endif