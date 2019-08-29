#Some of these terms are in the Hamiltonian tutorial.  Move them out so we can use them in the initial conditions
#and not recompute them!

import numpy as np

def compute_const_coeffs(eta, gamma, a):
    # Euler–Mascheroni constant $\gamma$

    c20 = 1.712
    c21 = -1.803949138004582
    c22 = -39.77229225266885
    c23 = 103.16588921239249

    KK = c20 + c21*eta + c22*eta*eta + c23*eta*eta*eta;                                                                                                                                                 
    EtaKKm1 = eta*KK - 1.

    # Tmp variables from Mathematica CSE on the coefficient expressions
    tmp4 = EtaKKm1*EtaKKm1*EtaKKm1
    tmp10 = EtaKKm1*EtaKKm1
    tmp7 = EtaKKm1*EtaKKm1*EtaKKm1*EtaKKm1
    tmp6 = KK*KK
    tmp16 = EtaKKm1**5
    tmp19 = EtaKKm1**6
    tmp18 = KK*KK*KK
    tmp23 = 4.*KK*tmp7
    tmp34 = EtaKKm1**7
    tmp28 = np.pi*np.pi
    tmp32 = 16.*KK*tmp16
    tmp37 = EtaKKm1**8
    tmp36 = KK*KK*KK*KK
    tmp64 = EtaKKm1**9

    kC0 = 0. + 4.*KK*tmp4 + 2.*tmp6*tmp7
    kC1 = 1.*KK*tmp10 - KK*tmp4
    kC2 = 0. + 2.*tmp10 - 1.3333333333333335*tmp18*tmp19 - 8.*tmp16*tmp6-8.*KK*tmp7
    kC3 = tmp23-2.*KK*tmp4 + 2.*tmp16*tmp6 - 2.*tmp6*tmp7
    kC4 = 0. + 31.333333333333332*tmp10 - 1.28125*tmp10*tmp28 + tmp32 + 8.*tmp18*tmp34 + 0.6666666666666666*tmp36*tmp37 - 4.*tmp4 + 24.*tmp19*tmp6 - 4.*KK*tmp7
    kC5 = -12.*KK*tmp16 + 2.*tmp18*tmp19 + tmp23 - 2.*tmp18*tmp34 + 8.*tmp16*tmp6 - 12.*tmp19*tmp6
    kC6 = 1.*KK*tmp16 - tmp16*tmp6 + 0.5*tmp19*tmp6 - KK*tmp7 + 0.5*tmp6*tmp7
    kC7 = -35.12753102199746*tmp10 + 25.6*gamma*tmp10 - 32.*KK*tmp19 + 4.443359375*tmp10*tmp28 + tmp32 - 32.*tmp18*tmp37 - 62.666666666666664*tmp4 + 2.5625*tmp28*tmp4 + 4.*tmp19*tmp6 - 64.*tmp34*tmp6 - 5.333333333333334*tmp36*tmp64 + 8.*tmp7 - 62.666666666666664*KK*tmp7 + 2.5625*KK*tmp28*tmp7 - 0.2666666666666661*KK**5*EtaKKm1**10
    kC8 = -10.*KK*tmp16 + 32.*KK*tmp19 - 12.*tmp18*tmp34 + 16.*tmp18*tmp37 - 1.3333333333333337*tmp36*tmp37 - 24.*tmp19*tmp6 + 48.*tmp34*tmp6 + 1.3333333333333337*tmp36*tmp64 - 2.*tmp7 + 2.*KK*tmp7
    kC9 = 4.*KK*tmp16 - 6.*KK*tmp19 - tmp18*tmp19 + 2.*tmp18*tmp34 - tmp18*tmp37 - 2.*tmp16*tmp6 + 8.*tmp19*tmp6 - 6.*tmp34*tmp6

    asq = a*a
    aft = asq*asq

    k0 = KK*(EtaKKm1 - 1)
    k1 = -2*(k0 + KK)*EtaKKm1
    k2 = kC0 + kC1*asq
    k3 = kC2 + kC3*asq
    k4 = kC4 + kC5*asq + kC6*aft
    k5 = kC7 + kC8*asq + kC9*aft
    k5l = EtaKKm1*EtaKKm1*64./5.

    d1 = -69.5
    d1v2 = -74.71 - 156.*eta + 627.5*eta*eta
    dheffSS = 2.75
    dheffSSv2 = 8.127 - 154.2*eta + 830.8*eta*eta

    return KK, kC0, kC1, kC2, kC3, kC4, kC5, kC6, kC7, kC8, kC9, k0, k1, k2, k3, k4, k5, k5l, d1, d1v2, dheffSS, dheffSSv2
