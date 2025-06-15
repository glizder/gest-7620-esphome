
#pragma once
#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace paj7620 {

class PAJ7620Component : public Component {
 public:
  void set_gesture_sensor(text_sensor::TextSensor *sensor) { gesture_sensor_ = sensor; }
  void setup() override;
  void loop() override;

 protected:
  text_sensor::TextSensor *gesture_sensor_{nullptr};
};

}  // namespace paj7620
}  // namespace esphome
