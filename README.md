# gest-7620-esphome

Minimal ESPHome `external_component` template for PAJ7620 gesture sensor.

## Usage

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/<your-user>/gest-7620-esphome
      ref: main

paj7620:
  name: "Lustro P Gesture"
```
