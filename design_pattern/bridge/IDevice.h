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
#ifndef IDEVICE_HPP_
#define IDEVICE_HPP_


/*
 * Remote is abstraction. IDevice is interface for different implementations.
 * */

class IDevice{
public:
	virtual bool isEnabled() = 0;

	virtual void enable() = 0;

	virtual void disable() = 0;

	virtual int getVolume() = 0;

	virtual void setVolume(int) = 0;

	virtual int getChannel() = 0;

	virtual void setChannel(int) = 0;

	virtual ~ IDevice(){}
};

#endif /* IDEVICE_HPP_ */
