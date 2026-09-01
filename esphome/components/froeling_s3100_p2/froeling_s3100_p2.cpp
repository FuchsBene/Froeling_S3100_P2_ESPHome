#include "esphome/core/log.h"
#include "froeling_s3100_p2.h"

namespace esphome::froeling_s3100_p2 {

static const char *TAG = "froeling_s3100_p2.component";

void FroelingComponent::setup() {
  // Code here should perform all component initialization,
  //  whether hardware, memory, or otherwise
}

void FroelingComponent::loop() {
  // Tasks here will be performed at every call of the main application loop.
  // Note: code here MUST NOT BLOCK (see below)
}

void FroelingComponent::dump_config(){
  ESP_LOGCONFIG(TAG, "Froeling Lambdatronic S3100 P2");                  

  // ESP_LOGCONFIG(TAG, "  foo = %s", TRUEFALSE(this->foo_));
  // ESP_LOGCONFIG(TAG, "  bar = %s", this->bar_.c_str());
  // ESP_LOGCONFIG(TAG, "  baz = %i", this->baz_);
}

}  // namespace esphome::froeling_s3100_p2