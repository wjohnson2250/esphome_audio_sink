#pragma once
#include "esphome/components/adf_pipeline/adf_pipeline.h"

namespace esphome {
namespace db_sound_meter {

class DBSoundMeter : public esp_adf::ADFPipelineSinkElement {
 public:
  void setup() override;
  void on_process(AudioChunk *chunk) override;
};

}  // namespace db_sound_meter
}  // namespace esphome
