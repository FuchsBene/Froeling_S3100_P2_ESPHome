'''
    * __init__.py
    * Config validation and code generation for the ESPHome component.
    *     
    * Froeling_S3100_P2_ESPHome
    * Copyright (c) 2026 Benedikt Fuchs <github.com/FuchsBene>
'''

import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.components import uart
from esphome.const import CONF_ID


froeling_component_ns = cg.esphome_ns.namespace("froeling_s3100_p2")
FroelingComponent = froeling_component_ns.class_("FroelingComponent", cg.Component, uart.UARTDevice)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FroelingComponent),
}).extend(uart.UART_DEVICE_SCHEMA).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    await uart.register_uart_device(var, config)