#ifndef XCFUN_H
#define XCFUN_H

#define XCFUN_API_VERSION 1

#ifdef __cplusplus
extern "C" {
#endif

#define XC_MAX_ORDER 2  

// Used for regularizing input
#define XC_TINY_DENS 1e-14
  
  enum xc_mode
    {
      XC_MODE_UNSET = -1,
      XC_PARTIAL_DERIVATIVES,
      XC_POTENTIAL,
      XC_CONTRACTED,
      XC_NR_MODES
    };

  enum xc_functional_id
    {
      XC_LYPC,
      /*      XC_SLATERX,
      XC_VWN5C,
      XC_BECKEX,
      XC_BECKECORRX,
      XC_BECKESRX,
      XC_OPTX,
      XC_LYPC,
      XC_PBEX,
      XC_REVPBEX,
      XC_RPBEX,
      XC_PBEC,
      XC_SPBEC,
      XC_VWN_PBEC,
      XC_LDAERFX,
      XC_LDAERFC,
      XC_LDAERFC_JT,
      XC_KTX,
      XC_TFK,
      XC_PW91X,
      XC_PW91K,
      XC_PW92C,
      XC_M05X,
      XC_M05X2X,
      XC_M06X,
      XC_M06X2X,
      XC_M06LX,
      XC_M06HFX,
      XC_BRX,
      XC_M05X2C,
      XC_M05C,
      XC_M06C,
      XC_M06LC,
      XC_M06X2C,
      XC_TPSSC,
      XC_TPSSX,
      XC_REVTPSSC,
      XC_REVTPSSX,*/
      XC_NR_FUNCTIONALS
    };

  enum xc_parameter
    {
      XC_RANGESEP_MU = XC_NR_FUNCTIONALS,
      XC_NR_PARAMETERS_AND_FUNCTIONALS
    };

  enum xc_vars
    {
      XC_VARS_UNSET=-1,
      XC_A,
      XC_N,
      XC_A_B,
      XC_N_S,
      XC_A_GAA,
      XC_N_GNN,
      XC_A_GAA_LAPA,
      XC_A_GAA_TAUA,
      XC_N_GNN_LAPN,
      XC_N_GNN_TAUN,
      XC_A_B_GAA_GAB_GBB,
      XC_N_S_GNN_GNS_GSS,
      XC_A_B_GAA_GAB_GBB_LAPA_LAPB,
      XC_A_B_GAA_GAB_GBB_TAUA_TAUB,
      XC_N_S_GNN_GNS_GSS_LAPN_LAPS,
      XC_N_S_GNN_GNS_GSS_TAUN_TAUS,
      /*      XC_A_B_GAX_GAY_GAZ_GBX_GBY_GBZ,
      XC_A_B_GAA_GAB_GBB_LAPA_LAPB_TAUA_TAUB,
      XC_A_B_GAX_GAY_GAZ_GBX_GBY_GBZ_LAPA_LAPB,
      XC_A_B_GAX_GAY_GAZ_GBX_GBY_GBZ_TAUA_TAUB,
      XC_A_B_GAX_GAY_GAZ_GBX_GBY_GBZ_LAPA_LAPB_TAUA_TAUB, */
      XC_NR_VARS
    };

  double xcfun_version(void);
  const char *xcfun_splash(void);
  int xcfun_test(void);
  
  typedef struct xc_functional_obj * xc_functional;

  xc_functional xc_new_functional(void);
  void xc_free_functional(xc_functional fun);

  void xc_set_mode(xc_functional fun, enum xc_mode mode);

  // Set weight of functional or value of parameter
  void xc_set(xc_functional fun, int item, double value);
  double xc_get(xc_functional fun, int item);

  // Which variables to use/differentiatiate wrt to
  int xc_try_vars(xc_functional fun, enum xc_vars vars);
  int xc_try_order(xc_functional fun, int order);

  // Length of the result[] argument to eval()
  int xc_output_length(xc_functional fun);

  // Evaluate the functional at density
  void xc_eval(xc_functional fun,
	       const double *density,
	       double *result);
  /* Vector version of xc_eval. 
     density_pitch = density[start_of_second_point] - density[start_of_first_point],
     likewise for result_pitch. */
  void xc_eval_vec(xc_functional fun, int nr_points,
		   const double *density,
		   int density_pitch,
		   double *result,
		   int result_pitch);


  // Index into result[] for derivative with given index (length as input_length() )
  int xc_derivative_index(xc_functional fun, const int derivative[]);

  /* Discover and manipulate settings */

  // Return the internal name of setting param
  const char *xc_name(int param);
  // Describe in one line what the setting does
  const char *xc_short_description(int param);
  // Long description of the setting, ends with a \n
  const char *xc_long_description(int param);

#ifdef __cplusplus
} // End of extern "C"
#endif

// Derivative indices into xc_eval output in partial derivative mode

#define XC_D0 0
#define XC_D1 1
#define XC_D2 2

#define XC_D00 0
#define XC_D10 1
#define XC_D01 2
#define XC_D20 3
#define XC_D11 4
#define XC_D02 5

#define XC_D00000 0
#define XC_D10000 1
#define XC_D01000 2
#define XC_D00100 3
#define XC_D00010 4
#define XC_D00001 5
#define XC_D20000 6
#define XC_D11000 7
#define XC_D10100 8
#define XC_D10010 9
#define XC_D10001 10
#define XC_D02000 11
#define XC_D01100 12
#define XC_D01010 13
#define XC_D01001 14
#define XC_D00200 15
#define XC_D00110 16
#define XC_D00101 17
#define XC_D00020 18
#define XC_D00011 19
#define XC_D00002 20

#endif
