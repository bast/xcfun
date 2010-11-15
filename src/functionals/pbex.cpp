#include "functional.h"
#include "pbex.h"

// original PBE exchange functional

template<class num>
static num ENERGY_FUNCTION(XC_PBEX)(const densvars<num> &d)
{
  return pbex::energy_pbe_ab(pbex::R_pbe,d.a,d.gaa) 
    + pbex::energy_pbe_ab(pbex::R_pbe,d.b,d.gbb);
}

NEW_GGA_FUNCTIONAL(XC_PBEX);
SHORT_DESCRIPTION(XC_PBEX) =  "PBE Exchange Functional";
LONG_DESCRIPTION(XC_PBEX) =
	     "PBE Exchange Functional\n"
	     "J. P. Perdew, K. Burke, and M. Ernzerhof, "
	     "Phys. Rev. Lett 77, 3865 (1996)\n"
	     "Implemented by Ulf Ekstrom and Andre Gomes.\n";
TEST_VARS(XC_PBEX) = XC_A_B_GAA_GAB_GBB;
TEST_ORDER(XC_PBEX) = 2;
TEST_THRESHOLD(XC_PBEX) = 1e-11;
TEST_IN(XC_PBEX) =  {0.39E+02, 0.38E+02, 0.81E+06, 0.82E+06,0.82E+06};
 TEST_OUT(XC_PBEX) = {
    -0.276589791995E+03,

    -0.382556082420E+01,
    -0.378108116179E+01,
    -0.174145337536E-04,
    0.000000000000E+00,
    -0.175120610339E-04,

    -0.429564214817E-01,
    0.000000000000E+00,
    0.185237729809E-06,
    0.000000000000E+00,
    0.000000000000E+00,
    -0.424802511645E-01,
    0.000000000000E+00,
    0.000000000000E+00,
    0.161839553501E-06,
    0.740514207206E-11,
    0.000000000000E+00,
    0.000000000000E+00,
    0.000000000000E+00,
    0.000000000000E+00,
    0.786563034093E-11,
  };
 
