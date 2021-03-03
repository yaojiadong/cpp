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


#include "test_adapter.hpp"

#include <iostream>
#include "SquarePeg.hpp"
#include "SquarePegAdapter.hpp"
#include "RoundHole.hpp"


void test_adapter(){

	RoundHole round_hole{3};
	SquarePeg square_peg{5};
	SquarePegAdapter square_peg_adapter{square_peg};

	std::cout<<round_hole.fit(square_peg_adapter);
}
