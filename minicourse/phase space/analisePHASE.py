import numpy as np
import matplotlib.pyplot as plt

N = 33300
d = 30 

wins = np.loadtxt(f'samples/wins_N_{N}.dat', unpack=True)


wins = np.reshape(wins, (d, d))

gb = np.linspace(.1, 1., d)
rhoa = np.linspace(.1, 1., d)


plt.figure(layout='constrained')
plt.pcolormesh(gb, rhoa, wins.T)
plt.colorbar()
plt.ylabel(r'$\rho_{A}$')
plt.xlabel(r'$g_{B}$')
plt.title(f'N = {N}')
plt.savefig(f'samples/phasespace_N_{N}.png', dpi=400)



