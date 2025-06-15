import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_ID, CONF_NAME

paj7620_ns = cg.esphome_ns.namespace("paj7620")
PAJ7620Component = paj7620_ns.class_("PAJ7620Component", cg.Component)

CONF_GESTURE = "gesture"

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(PAJ7620Component),
    cv.Required(CONF_GESTURE): text_sensor.text_sensor_schema(CONF_NAME),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    # 👇 zarejestruj zmienną (to rozwiązuje błąd z ID!)
    var = cg.new_variable(config[CONF_ID], PAJ7620Component)
    await cg.register_component(var, config)

    # 👇 dodaj sensor
    gesture = await text_sensor.new_text_sensor(config[CONF_GESTURE])
    cg.add(var.set_gesture_sensor(gesture))
