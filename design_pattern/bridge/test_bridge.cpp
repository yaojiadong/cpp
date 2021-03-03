/**
 * \brief           Template header file
 * \compiler        Cosmic S12X
 * \controller      Freescale Tomar
 *
 * \file
 * \copyright       COPYRIGHT (C) Brose Fahrzeugteile GmbH & Co. KG, Bamberg
 * \copyright       ALL RIGHTS RESERVED
 * \copyright       The copying, use, distribution or disclosure of the
 *                  confidential and proprietary information contained in this
 *                  document(s) is strictly prohibited without prior written
 *                  consent. Any breach shall subject the infringing party to
 *                  remedies. The owner reserves all rights in the event of the
 *                  grant of a patent or the registration of a utility model
 *                  or design.
 */
#ifndef CLIENT_CPP_
#define CLIENT_CPP_

#include <iostream>
#include "Remote.hpp"
#include "Radio.hpp"
#include "Tv.hpp"

#include "test_bridge.hpp"

void test_bridge(){

	Radio radio;
	Remote remote{radio};

	std::cout<< "Radio volume is "<<radio.getVolume() <<std::endl;
	remote.volumeDown();
	std::cout<< "Radio volume is "<<radio.getVolume() <<std::endl;

}




#endif /* CLIENT_CPP_ */
