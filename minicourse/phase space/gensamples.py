import numpy as np
import matplotlib.pyplot as plt
import sys
import os

#rhoa = float(sys.argv[1])
#gb = float(sys.argv[1])

gb = np.linspace(.1, 1., 30)
rhoa = np.linspace(.1, 1., 30)

for g in gb:
    for r in rhoa:
        print(f'rhoa: {r} | gb: {g}', end='\r')
        os.system(f'./fast {r} {g}')
print()

