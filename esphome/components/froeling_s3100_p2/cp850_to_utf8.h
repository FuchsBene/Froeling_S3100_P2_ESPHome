/*
 * cp850_to_utf8.h
 * 
 * Originally from: https://github.com/dhoepfl/Radiator
 * Author: Daniel Höpfl <radiator@hoepfl.de>
 * 
 * Modified for Froeling_S3100_P2_ESPHome
 * Copyright (c) 2026 Benedikt Fuchs <github.com/FuchsBene>
 */

#pragma once
#include <string>
#include <cstdint>

namespace esphome::froeling_s3100_p2 {

std::string cp850toUTF8(const uint8_t *message, uint16_t len);

}  // namespace esphome::froeling_s3100_p2
