/*
Since it's so expensive to compute, instead of evaluating
psi_4 at all interior points, this functions evaluates it on a 
point-by-point basis.
 */
void psi4(const paramstruct *restrict params,
                  const int i0,const int i1,const int i2,
                  REAL *restrict xx[3], const REAL *restrict in_gfs, REAL *restrict aux_gfs) {
#include "./set_Cparameters.h"


    const int idx = IDX3S(i0,i1,i2);
    const REAL xx0 = xx[0][i0];const REAL xx1 = xx[1][i1];const REAL xx2 = xx[2][i2];
// Real part of psi_4, divided into 3 terms
    {
#include "Psi4re_pt0_lowlevel.h"
    }
    {
#include "Psi4re_pt1_lowlevel.h"
    }
    {
#include "Psi4re_pt2_lowlevel.h"
    }
// Imaginary part of psi_4, divided into 3 terms
    {
#include "Psi4im_pt0_lowlevel.h"
    }
    {
#include "Psi4im_pt1_lowlevel.h"
    }
    {
#include "Psi4im_pt2_lowlevel.h"
    }}
