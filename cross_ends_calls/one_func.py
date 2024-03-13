from numba import cfunc
import numpy as np

def integrand(t):
  return np.exp(-t) / t**2

nb_integrand = cfunc("float64(float64)")(integrand)

import scipy.integrate as si

def do_integrate(func):
  """
  Integrate the given function from 1.0 to +inf.
  """
  return si.quad(func, 1, np.inf)

print(do_integrate(integrand))

print(do_integrate(nb_integrand.ctypes))