
void SpinWeight_minus2_SphHarmonics(const int l, const int m, const REAL th, const REAL ph,
                                   REAL *reYlmswm2_l_m, REAL *imYlmswm2_l_m) {
if(l<0 || l>2 || m<-l || m>+l) {
    printf("ERROR: SpinWeight_minus2_SphHarmonics handles only l=[0,2] and only m=[-l,+l] is defined.\n");
    printf("       You chose l=%d and m=%d, which is out of these bounds.\n",l,m);
    exit(1);
}
switch(l) {
    case 0:
        switch(m) {
            case 0:
         {
                     *reYlmswm2_l_m = 0;
                     *imYlmswm2_l_m = 0;
         }
                  return;
        }  /* End switch(m) */
    case 1:
        switch(m) {
            case -1:
         {
                     *reYlmswm2_l_m = 0;
                     *imYlmswm2_l_m = 0;
         }
                  return;
            case 0:
         {
                     *reYlmswm2_l_m = 0;
                     *imYlmswm2_l_m = 0;
         }
                  return;
            case 1:
         {
                     *reYlmswm2_l_m = 0;
                     *imYlmswm2_l_m = 0;
         }
                  return;
        }  /* End switch(m) */
    case 2:
        switch(m) {
            case -2:
         {
                     *reYlmswm2_l_m = 0.5*sqrt(5)*((sin((1.0/2.0)*th))*(sin((1.0/2.0)*th))*(sin((1.0/2.0)*th))*(sin((1.0/2.0)*th)))*cos(2*ph)/sqrt(M_PI);
                     *imYlmswm2_l_m = -0.5*sqrt(5)*sin(2*ph)*((sin((1.0/2.0)*th))*(sin((1.0/2.0)*th))*(sin((1.0/2.0)*th))*(sin((1.0/2.0)*th)))/sqrt(M_PI);
         }
                  return;
            case -1:
         {
                     *reYlmswm2_l_m = 1.0*sqrt(5)*((sin((1.0/2.0)*th))*(sin((1.0/2.0)*th))*(sin((1.0/2.0)*th)))*cos(ph)*cos((1.0/2.0)*th)/sqrt(M_PI);
                     *imYlmswm2_l_m = -1.0*sqrt(5)*sin(ph)*((sin((1.0/2.0)*th))*(sin((1.0/2.0)*th))*(sin((1.0/2.0)*th)))*cos((1.0/2.0)*th)/sqrt(M_PI);
         }
                  return;
            case 0:
         {
                     *reYlmswm2_l_m = (1.0/16.0)*sqrt(30)*(1 - cos(2*th))/sqrt(M_PI);
                     *imYlmswm2_l_m = 0;
         }
                  return;
            case 1:
         {
                     *reYlmswm2_l_m = sqrt(5)*sin((1.0/2.0)*th)*cos(ph)*((cos((1.0/2.0)*th))*(cos((1.0/2.0)*th))*(cos((1.0/2.0)*th)))/sqrt(M_PI);
                     *imYlmswm2_l_m = sqrt(5)*sin(ph)*sin((1.0/2.0)*th)*((cos((1.0/2.0)*th))*(cos((1.0/2.0)*th))*(cos((1.0/2.0)*th)))/sqrt(M_PI);
         }
                  return;
            case 2:
         {
                     *reYlmswm2_l_m = (1.0/2.0)*sqrt(5)*cos(2*ph)*((cos((1.0/2.0)*th))*(cos((1.0/2.0)*th))*(cos((1.0/2.0)*th))*(cos((1.0/2.0)*th)))/sqrt(M_PI);
                     *imYlmswm2_l_m = (1.0/2.0)*sqrt(5)*sin(2*ph)*((cos((1.0/2.0)*th))*(cos((1.0/2.0)*th))*(cos((1.0/2.0)*th))*(cos((1.0/2.0)*th)))/sqrt(M_PI);
         }
                  return;
        }  /* End switch(m) */
    } /* End switch(l) */
} /* End function SpinWeight_minus2_SphHarmonics() */
