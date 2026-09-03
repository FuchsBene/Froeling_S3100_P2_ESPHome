/*
 * device.cpp 
 * Provides low-level protocol communication functions.
 * 
 * Originally from: https://github.com/dhoepfl/Radiator
 * Author: Daniel Höpfl <radiator@hoepfl.de>
 * 
 * Modified for Froeling_S3100_P2_ESPHome
 * Copyright (c) 2026 Benedikt Fuchs <github.com/FuchsBene>
 */

#include "device.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <cstring>

namespace esphome::froeling_s3100_p2 {

/**
 * Calculates the checksum of a device message.
 *
 * @param command The command structure whose checksum to calculate.
 * @return The 16 bit (unsigned) checksum.
 */
uint16_t checksum(const uint8_t *command)
{
   uint16_t crc = 0;
   for (int i = 0; i < 3 + command[2]; ++i) {
      crc += command[i];
   }
   return crc;
}

/**
 * Verify the checksum of a device message.
 *
 * @param command The message whose checksum should be verified.
 * @return true if the checksum was OK, false if the checksum did not match.
 */
bool checksum_verify(const uint8_t *command)
{
   uint16_t expected = checksum(command);
   uint16_t actual = (static_cast<uint16_t>(command[3 + command[2]]) << 8) | command[3 + command[2] + 1];

   return expected == actual;
}

/**
 * Builds a frame ready to be sent to device.
 *
 * @param cmd Command to send (2 bytes)
 * @param data Data to send
 * @param len Length of the data
 * @param out_buffer Buffer to store the built frame
 * @return The total length of the built frame (len + 5).
 */
size_t build_frame(const char cmd[2], const uint8_t *data, uint8_t len, uint8_t *out_buffer)
{
   out_buffer[0] = static_cast<uint8_t>(cmd[0]);
   out_buffer[1] = static_cast<uint8_t>(cmd[1]);
   out_buffer[2] = len;
   ::memcpy(out_buffer + 3, data, len);

   uint16_t crc = checksum(out_buffer);
   out_buffer[len + 3] = (crc & 0xff00) >> 8;
   out_buffer[len + 4] = crc & 0x00ff;

   return len + 5;
}

} // namespace esphome::froeling_s3100_p2

