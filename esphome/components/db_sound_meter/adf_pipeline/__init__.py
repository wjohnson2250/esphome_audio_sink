"""ADF pipeline sink platform implementation: db_sound_meter"""
print("✅ db_sound_meter.adf_pipeline platform was loaded")

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.components import adf_pipeline as esp_adf

DEPENDENCIES = ["adf_pipeline"]
AUTO_LOAD = ["adf_pipeline"]

CONF_TYPE = "type"
db_sound_meter_ns = cg.esphome_ns.namespace("db_sound_meter")
DBSoundMeter = db_sound_meter_ns.class_("DBSoundMeter", esp_adf.ADFPipelineSink)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(DBSoundMeter),
    cv.Required(CONF_TYPE): cv.one_of("audio_out", lower=True),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID], DBSoundMeter())
    return var

