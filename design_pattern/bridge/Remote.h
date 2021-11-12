#ifndef REMOTE_HPP_
#define REMOTE_HPP_

/*
 * Remote is abstraction. IDevice is interface for different implementations.
 * */

#include "IDevice.h"

class Remote {
public:
  Remote(IDevice *device) : device_{device} {}

  void togglePower() {
    device_->isEnabled() ? device_->disable() : device_->enable();
  }

  void volumeDown() { device_->setVolume(device_->getVolume() - 1); }

  void volumeUp() { device_->setVolume(device_->getVolume() + 1); }

  void channelDown() { device_->setChannel(device_->getChannel() - 1); }

  void channelUp() { device_->setChannel(device_->getChannel() + 1); }

private:
  IDevice *device_;
};

#endif /* REMOTE_HPP_ */
