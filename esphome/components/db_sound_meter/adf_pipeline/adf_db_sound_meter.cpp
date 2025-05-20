#include "adf_db_sound_meter.h"
#include "esphome/core/log.h"
#include <cmath>

namespace esphome {
namespace db_sound_meter {

static const char *const TAG = "db_sound_meter";

void DBSoundMeter::setup() { ESP_LOGI(TAG, "Sound meter setup complete."); }

void DBSoundMeter::on_process(esp_adf::AudioChunk *chunk) {
  const int16_t *samples = reinterpret_cast<const int16_t *>(chunk->data());
  size_t count = chunk->length() / sizeof(int16_t);

  float sum_squares = 0.0f;
  for (size_t i = 0; i < count; i++) {
    float sample = samples[i] / 32768.0f;
    sum_squares += sample * sample;
  }

  float rms = sqrtf(sum_squares / count);
  float db = 20.0f * log10f(rms + 1e-9f);

  ESP_LOGD(TAG, "Computed dB level: %.2f", db);
}

}  // namespace db_sound_meter
}  // namespace esphome
