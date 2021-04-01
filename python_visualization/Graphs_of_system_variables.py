import pandas as pd
import numpy as np
import datetime
from datetime import date, timedelta

import matplotlib.pyplot as plt

system_variables = pd.read_csv ("../data/Simulation_Results/system_variables_python.txt", sep= ",",
                                names= ["center_of_mass_x", "center_of_mass_y", "center_of_mass_z",
                                        "angular_mom_x", "angular_mom_y", "angular_mom_z",
                                        "hamiltonian"])


k = system_variables["center_of_mass_x"][0] #first row is k, i.e R-K step in days

system_variables.drop([0], inplace=True)

params = {'figure.figsize': (11.5, 8), # standard A4
          'font.size': 12,
          'figure.autolayout': True,
          'legend.fontsize': 10,
          #'legend.loc': 'upper center',
          #'legend.bbox_to_anchor' : (10,0.5,0.5,0.5)
          #'legend.handlelength': 4=(0.5, 0., 0.5, 0.5)
         }
#print(plt.rcParams.keys())  # prints every parameter key if need to edit anyhthing else
plt.rcParams.update(params)

all_dates = range(len(system_variables))

fig = plt.figure()

Hamiltonian_plot = fig.add_subplot(2,1,1)

Hamiltonian_plot.plot (all_dates, system_variables["hamiltonian"] )
Hamiltonian_plot.set_xlabel('Year')
Hamiltonian_plot.set_ylabel('Energy (au^2*kg/day^-2')
Hamiltonian_plot.set_title('Hamiltonian of solar system')

Angular_plot = fig.add_subplot(2,1,2)

angular_momentum_modulus = np.sqrt( system_variables["angular_mom_x"]**2 + system_variables["angular_mom_y"]**2 + system_variables["angular_mom_z"]**2 )

print (angular_momentum_modulus)
Angular_plot.plot (all_dates, angular_momentum_modulus)
Angular_plot.set_xlabel('Year')
Angular_plot.set_ylabel('Angular momentum modulus')
Angular_plot.set_title('Angular momentum wrt barycenter of Solar System')




plt.show()