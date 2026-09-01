import esphome.config_validation as cv
import esphome.codegen as cg

from esphome.const import CONF_ID

#CONF_FOO = "foo"
#CONF_BAR = "bar"
#CONF_BAZ = "baz"

froeling_component_ns = cg.esphome_ns.namespace("froeling_s3100_p2")
FroelingComponent = froeling_component_ns.class_("FroelingComponent", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FroelingComponent),
    #cv.Required(CONF_FOO): cv.boolean,
    #cv.Optional(CONF_BAR): cv.string,
    #cv.Optional(CONF_BAZ): cv.int_range(0, 255),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await cg.register_component(var, config)

    #cg.add(var.set_foo(config[CONF_FOO]))
    #if bar := config.get(CONF_BAR):
    #    cg.add(var.set_bar(bar))
    #if baz := config.get(CONF_BAZ):
    #    cg.add(var.set_baz(baz))