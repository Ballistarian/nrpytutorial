
    void enforce_detgammabar_constraint(rfm_struct *restrict rfmstruct,
                                        const paramstruct *restrict params, REAL *restrict in_gfs) {
    #include "set_Cparameters.h"
    #pragma omp parallel for
for(int i2=0; i2<Nxx_plus_2NGHOSTS2; i2++) {
#include "rfm_files/rfm_struct__read2.h"
    for(int i1=0; i1<Nxx_plus_2NGHOSTS1; i1++) {
#include "rfm_files/rfm_struct__read1.h"
        for(int i0=0; i0<Nxx_plus_2NGHOSTS0; i0++) {
            #include "rfm_files/rfm_struct__read0.h"
            /* 
             * NRPy+ Finite Difference Code Generation, Step 1 of 1: Read from main memory and compute finite difference stencils:
             */
            const double hDD00 = in_gfs[IDX4S(HDD00GF, i0,i1,i2)];
            const double hDD01 = in_gfs[IDX4S(HDD01GF, i0,i1,i2)];
            const double hDD02 = in_gfs[IDX4S(HDD02GF, i0,i1,i2)];
            const double hDD11 = in_gfs[IDX4S(HDD11GF, i0,i1,i2)];
            const double hDD12 = in_gfs[IDX4S(HDD12GF, i0,i1,i2)];
            const double hDD22 = in_gfs[IDX4S(HDD22GF, i0,i1,i2)];
            /* 
             * NRPy+ Finite Difference Code Generation, Step 2 of 1: Evaluate SymPy expressions and write to main memory:
             */
            in_gfs[IDX4S(HDD00GF, i0, i1, i2)] = cbrt(fabs(((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))/(2*((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD01*hDD02*hDD12 - ((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD12)*(hDD12))*(hDD00 + 1) - ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD02)*(hDD02))*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0))) - ((f0_of_xx0)*(f0_of_xx0))*((hDD01)*(hDD01))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))) + (hDD00 + 1)*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0)))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))))*(hDD00 + 1) - 1;
            in_gfs[IDX4S(HDD01GF, i0, i1, i2)] = hDD01*cbrt(fabs(((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))/(2*((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD01*hDD02*hDD12 - ((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD12)*(hDD12))*(hDD00 + 1) - ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD02)*(hDD02))*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0))) - ((f0_of_xx0)*(f0_of_xx0))*((hDD01)*(hDD01))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))) + (hDD00 + 1)*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0)))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))));
            in_gfs[IDX4S(HDD02GF, i0, i1, i2)] = hDD02*cbrt(fabs(((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))/(2*((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD01*hDD02*hDD12 - ((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD12)*(hDD12))*(hDD00 + 1) - ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD02)*(hDD02))*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0))) - ((f0_of_xx0)*(f0_of_xx0))*((hDD01)*(hDD01))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))) + (hDD00 + 1)*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0)))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))));
            in_gfs[IDX4S(HDD11GF, i0, i1, i2)] = cbrt(fabs(((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))/(2*((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD01*hDD02*hDD12 - ((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD12)*(hDD12))*(hDD00 + 1) - ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD02)*(hDD02))*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0))) - ((f0_of_xx0)*(f0_of_xx0))*((hDD01)*(hDD01))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))) + (hDD00 + 1)*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0)))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))))*(hDD11 + 1) - 1;
            in_gfs[IDX4S(HDD12GF, i0, i1, i2)] = hDD12*cbrt(fabs(((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))/(2*((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD01*hDD02*hDD12 - ((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD12)*(hDD12))*(hDD00 + 1) - ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD02)*(hDD02))*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0))) - ((f0_of_xx0)*(f0_of_xx0))*((hDD01)*(hDD01))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))) + (hDD00 + 1)*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0)))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))));
            in_gfs[IDX4S(HDD22GF, i0, i1, i2)] = cbrt(fabs(((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))/(2*((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD01*hDD02*hDD12 - ((f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD12)*(hDD12))*(hDD00 + 1) - ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*((hDD02)*(hDD02))*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0))) - ((f0_of_xx0)*(f0_of_xx0))*((hDD01)*(hDD01))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))) + (hDD00 + 1)*(((f0_of_xx0)*(f0_of_xx0))*hDD11 + ((f0_of_xx0)*(f0_of_xx0)))*(((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1))*hDD22 + ((f0_of_xx0)*(f0_of_xx0))*((f1_of_xx1)*(f1_of_xx1)))))*(hDD22 + 1) - 1;
            
            
        } // END LOOP: for(int i0=0; i0<Nxx_plus_2NGHOSTS0; i0++)
    } // END LOOP: for(int i1=0; i1<Nxx_plus_2NGHOSTS1; i1++)
} // END LOOP: for(int i2=0; i2<Nxx_plus_2NGHOSTS2; i2++)
}
