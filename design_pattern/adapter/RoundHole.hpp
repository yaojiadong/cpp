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
#ifndef ROUNDHOLE_HPP_
#define ROUNDHOLE_HPP_

#include "RoundPeg.hpp"

class RoundHole{
public:
	RoundHole(int radius = 0):radius_{radius}{}

	int radius()const {return radius_;}

	bool fit(const RoundPeg& rp){return rp.radius() == this->radius_;}

private:
		int radius_;
};


#endif /* ROUNDHOLE_HPP_ */
