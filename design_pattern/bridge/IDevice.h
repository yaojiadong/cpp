#ifndef IDEVICE_HPP_
#define IDEVICE_HPP_

/*
 * Remote is abstraction. IDevice is interface for different implementations.
 * */

class IDevice {
public:
  virtual bool isEnabled() = 0;

  virtual void enable() = 0;

  virtual void disable() = 0;

  virtual int getVolume() = 0;

  virtual void setVolume(int) = 0;

  virtual int getChannel() = 0;

  virtual void setChannel(int) = 0;

  virtual ~IDevice() {}
};

#endif /* IDEVICE_HPP_ */
