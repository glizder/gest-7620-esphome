
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_NAME
from esphome.components import text_sensor

paj7620_ns = cg.esphome_ns.namespace("paj7620")
PAJ7620Component = paj7620_ns.class_("PAJ7620Component", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(PAJ7620Component),
    cv.Required(CONF_NAME): cv.string,
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_PAJ7620Component()
    await cg.register_component(var, config)
