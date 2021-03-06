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
#ifndef TV_HPP_
#define TV_HPP_

#include "IDevice.h"

class Tv : public IDevice{

public:
	Tv(bool enabled=false, int channel=1, int volume=50):enabled_{enabled},channel_{channel},volume_{volume}{}

	bool isEnabled() override{return enabled_;}

	void enable() override{enabled_ = true;}

	void disable() override{enabled_ = false;}

	int getVolume() override{return volume_;}

	void setVolume(int volume) override{volume_ = volume;}

	int getChannel() override{return channel_;}

	void setChannel(int channel) override{channel_ = channel;}

private:
	bool enabled_;
	int channel_;
	int volume_;
};



#endif /* TV_HPP_ */
