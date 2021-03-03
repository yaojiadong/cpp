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
#ifndef SQUAREPEGADAPTER_HPP_
#define SQUAREPEGADAPTER_HPP_

/*
 * Is the square peg fit to the round hole?
 * Since the round hole only accepts round peg,
 * the square peg adapter facilitates the check if a square peg fits the round hole.
 * */

#include <cmath>
#include "RoundPeg.hpp"
#include "SquarePeg.hpp"


class SquarePegAdapter : public RoundPeg{

public:
	SquarePegAdapter(SquarePeg sp):square_peg_{sp}{}

	int radius() const override  {return static_cast<int>(square_peg_.width()*std::sqrt(2)*2);}

private:
	SquarePeg square_peg_;
};



#endif /* SQUAREPEGADAPTER_HPP_ */
