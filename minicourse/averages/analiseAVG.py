import numpy as np
import matplotlib.pyplot as plt
import sys

# Setting parameters
N = 50
rhoa = float(sys.argv[1])
gb = float(sys.argv[2])

# Openning file
numB = np.loadtxt(f'avg_rhoa_{rhoa:.2f}_gb_{gb:.2f}.dat', unpack=True)

numB = np.asarray(numB)
numA = N - numB 

plt.plot(numA, label=r'$N_{A}$ '+'(Big)')
plt.plot(numB, label=r'$N_{B}$'+'(Small)')
plt.legend()
plt.xlabel('t')
plt.ylabel(r'$\left \langle N \right \rangle$')
plt.title(r'$\rho_{A} = $'+f'{rhoa}'+r' $\mid g_{B} = $'+f'{gb}')
plt.savefig('avgnums.png', dpi=400)
