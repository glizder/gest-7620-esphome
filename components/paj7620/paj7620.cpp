
#include "paj7620.h"
#include <Wire.h>
#include <PAJ7620.h>

namespace esphome {
namespace paj7620 {

void PAJ7620Component::setup() {
  Wire.begin();
  uint8_t error = paj7620Init();
  if (error) {
    ESP_LOGE("PAJ7620", "Init ERROR, code: %d", error);
  } else {
    ESP_LOGI("PAJ7620", "Init OK");
  }
}

void PAJ7620Component::loop() {
  uint8_t data = 0;
  if (paj7620ReadReg(0x43, 1, &data)) {
    ESP_LOGW("PAJ7620", "Read ERROR");
    return;
  }

  const char* gesture = nullptr;
  switch (data) {
    case GES_RIGHT_FLAG: gesture = "right"; break;
    case GES_LEFT_FLAG: gesture = "left"; break;
    case GES_UP_FLAG: gesture = "up"; break;
    case GES_DOWN_FLAG: gesture = "down"; break;
    case GES_FORWARD_FLAG: gesture = "forward"; break;
    case GES_BACKWARD_FLAG: gesture = "backward"; break;
    case GES_CLOCKWISE_FLAG: gesture = "clockwise"; break;
    case GES_COUNT_CLOCKWISE_FLAG: gesture = "counter_clockwise"; break;
    case GES_WAVE_FLAG: gesture = "wave"; break;
    default: gesture = nullptr;
  }

  if (gesture && gesture_sensor_ != nullptr) {
    ESP_LOGD("PAJ7620", "Detected gesture: %s", gesture);
    gesture_sensor_->publish_state(gesture);
  }
}

}  // namespace paj7620
}  // namespace esphome
