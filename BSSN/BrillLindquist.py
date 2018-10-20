# This module sets up Brill-Lindquist initial data in terms of
# the variables used in BSSN_RHSs.py

# Author: Zachariah B. Etienne
#         zachetie **at** gmail **dot* com

# # Start-to-Finish Example: Setting up Two Black Hole Initial Data, in Curvilinear Coordinates
# 
# ## This module sets up initial data for a merging black hole system in *spherical coordinates*
# 
# <font color='green'>**This module has been validated to exhibit convergence to zero of the Hamiltonian constraint violation at the expected order to the exact solution (see plot at bottom), and all quantities have been validated against the [original SENR code](https://bitbucket.org/zach_etienne/nrpy).**</font>
# 
# ### NRPy+ Source Code for this module: [BSSN/BSSN_RHSs.py](../edit/BSSN/BSSN_RHSs.py), [BSSN/BSSN_Constraints.py](../edit/BSSN/BSSNConstraints.py)
# 
# 
# Here we use NRPy+ to generate initial data for two black holes (Brill-Lindquist, [Brill & Lindquist, Phys. Rev. 131, 471, 1963](https://journals.aps.org/pr/abstract/10.1103/PhysRev.131.471); see also Eq. 1 of [Brandt & Brügmann, arXiv:gr-qc/9711015v1](https://arxiv.org/pdf/gr-qc/9711015v1.pdf)).
#

# ## Setting up the initial data
# 
# ### Brill-Lindquist initial data ([Brill & Lindquist, Phys. Rev. 131, 471, 1963](https://journals.aps.org/pr/abstract/10.1103/PhysRev.131.471); see also Eq. 1 of [Brandt & Brügmann, arXiv:gr-qc/9711015v1](https://arxiv.org/pdf/gr-qc/9711015v1.pdf)) may be written in terms of the BSSN conformal factor and ADM extrinsic curvature as
# 
# $$\psi = e^{\phi} = 1 + \sum_{i=1}^N \frac{m_{(i)}}{2 \left|\vec{r}_{(i)} - \vec{r}\right|};\quad K_{ij}=0.$$
# 
# These data consist of $N$ nonspinning black holes initially at rest. This module restricts to the case of two such black holes, positioned along either the $x$ or $z$ axis. Here, we implement $N=2$.
# 
# **Inputs for $\psi$**:
# * The position and (bare) mass of black hole 1: $\left(x_{(1)},y_{(1)},z_{(1)}\right)$ and $m_{(1)}$, respectively
# * The position and (bare) mass of black hole 2: $\left(x_{(2)},y_{(2)},z_{(2)}\right)$ and $m_{(2)}$, respectively
# 
# **Additional variables needed for spacetime evolution**:
# * Desired coordinate system
# * Desired initial lapse $\alpha$ and shift $\beta^i$
# 
# **Transformation to curvilinear coordinates**:
# * Once the above variables have been set in Cartesian coordinates, we will apply the appropriate coordinate transformations and tensor rescalings ([described in the BSSN NRPy+ tutorial module](Tutorial-BSSNCurvilinear.ipynb))

# Step P0: Load needed modules
import sympy as sp
import NRPy_param_funcs as par
from outputC import *
import indexedexp as ixp
import reference_metric as rfm
import BSSN.CartesianADMID_to_BSSNCurvilinearID as ctob
import BSSN.BSSN_ID_function_string as bIDf

def BrillLindquist():
    # Step P1b: Set up needed reference metric quantities
    rfm.reference_metric()

    thismodule = "Brill-Lindquist"
    BH1_posn_x,BH1_posn_y,BH1_posn_z = par.Cparameters("REAL", thismodule, ["BH1_posn_x","BH1_posn_y","BH1_posn_z"])
    BH1_mass = par.Cparameters("REAL", thismodule, ["BH1_mass"])
    BH2_posn_x,BH2_posn_y,BH2_posn_z = par.Cparameters("REAL", thismodule, ["BH2_posn_x","BH2_posn_y","BH2_posn_z"])
    BH2_mass = par.Cparameters("REAL", thismodule, ["BH2_mass"])

    # Step 0: Set spatial dimension (must be 3 for BSSN)
    DIM = 3
    par.set_parval_from_str("grid::DIM",DIM)

    global Cartxyz, gammaCartDD, KCartDD, alphaCart, betaCartU, BCartU
    Cartxyz = ixp.declarerank1("Cartxyz")

    # Step 1: Set psi, the conformal factor:
    psi = sp.sympify(1)
    psi += BH1_mass / ( 2 * sp.sqrt((Cartxyz[0]-BH1_posn_x)**2 + (Cartxyz[1]-BH1_posn_y)**2 + (Cartxyz[2]-BH1_posn_z)**2) )
    psi += BH2_mass / ( 2 * sp.sqrt((Cartxyz[0]-BH2_posn_x)**2 + (Cartxyz[1]-BH2_posn_y)**2 + (Cartxyz[2]-BH2_posn_z)**2) )

    # Step 2: Set all needed ADM variables in Cartesian coordinates
    gammaCartDD = ixp.zerorank2()
    KCartDD     = ixp.zerorank2() # K_{ij} = 0 for these initial data
    for i in range(DIM):
        gammaCartDD[i][i] = psi**4

    alphaCart = 1/psi**2
    betaCartU = ixp.zerorank1() # We generally choose \beta^i = 0 for these initial data
    BCartU    = ixp.zerorank1() # We generally choose B^i = 0 for these initial data

    cf,hDD,lambdaU,aDD,trK,alpha,vetU,betU = \
        ctob.Convert_Cartesian_ADM_to_BSSN_curvilinear(Cartxyz, gammaCartDD,KCartDD,alphaCart,betaCartU,BCartU)

    global returnfunction
    returnfunction = bIDf.BSSN_ID_function_string(cf,hDD,lambdaU,aDD,trK,alpha,vetU,betU)