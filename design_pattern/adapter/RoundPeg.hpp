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
#ifndef ROUNDPEG_HPP_
#define ROUNDPEG_HPP_

class RoundPeg{
public:
	RoundPeg(int radius=0):radius_{radius}{}

	virtual int radius() const {return radius_;}

	virtual ~RoundPeg(){}

private:
	int radius_;
};



#endif /* ROUNDPEG_HPP_ */
