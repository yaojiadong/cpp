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
#ifndef REMOTE_HPP_
#define REMOTE_HPP_

/*
 * Remote is abstraction. IDevice is interface for different implementations.
 * */

#include "IDevice.hpp"

class Remote{
public:
	Remote(IDevice& device)
	: device_{device}
	{}

	void togglePower(){device_.isEnabled()? device_.disable() : device_.enable();}

	void volumeDown(){device_.setVolume(device_.getVolume()-1);}

	void volumeUp(){device_.setVolume(device_.getVolume()+1);}

	void channelDown(){device_.setChannel(device_.getChannel()-1);}

	void channelUp(){device_.setChannel(device_.getChannel()+1);}

private:
	IDevice& device_;
};


#endif /* REMOTE_HPP_ */
