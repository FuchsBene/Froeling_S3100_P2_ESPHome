/*
 * device.h
 * 
 * Froeling_S3100_P2_ESPHome
 * Copyright (c) 2026 Benedikt Fuchs <github.com/FuchsBene>
 */

#pragma once
#include <cstdint>
#include <cstddef>

namespace esphome::froeling_s3100_p2 {

uint16_t checksum(const uint8_t *command);
bool checksum_verify(const uint8_t *command);

size_t build_frame(const char cmd[2], const uint8_t *data, uint8_t len, uint8_t *out_buffer);

} // namespace esphome::froeling_s3100_p2
