#ifndef CLIENT_CPP_
#define CLIENT_CPP_

#include "test_bridge.h"

#include "Radio.h"
#include "Remote.h"
#include "Tv.h"
#include <iostream>

void test_bridge() {

  Radio *radio = new Radio{};
  Tv *tv = new Tv{};
  Remote remote_radio{radio};
  Remote remote_tv{tv};

  std::cout << "Radio volume is " << radio->getVolume() << std::endl;
  remote_radio.volumeDown();
  std::cout << "Radio volume is " << radio->getVolume() << std::endl;

  std::cout << "Radio volume is " << tv->getVolume() << std::endl;
  remote_tv.volumeUp();
  std::cout << "Radio volume is " << tv->getVolume() << std::endl;

  delete radio;
  delete tv;
}

#endif /* CLIENT_CPP_ */
