import pandas as pd
import numpy as np

import pandas as pd
import numpy as np


import matplotlib.pyplot as plt
import matplotlib.animation as animation

### Tis part of the script reads the data from results.txt
### and stores it in an array of pandas dataframes called solar_system_iterations

number_of_planets = 10
planet_colours = [1,2,3,4,5,6,7,8,9,10]



solar_system_dataframe = pd.read_csv("../data/Simulation_Results/planets_p_q_python.txt", sep=",", header=None,
                                     names=["X", "Y", "Z", "V_x", "V_y", "V_z"])

print (solar_system_dataframe.iloc[lambda x: x.index % number_of_planets == 0]["X"])


### rc.Params, i.e parameters of figure and plot
params = {'figure.figsize': (50, 20), # standard A4
          'font.size': 12,
          'figure.autolayout': True,
          'legend.fontsize': 10,
          #'legend.loc': 'upper center',
          #'legend.bbox_to_anchor' : (10,0.5,0.5,0.5)
          #'legend.handlelength': 4=(0.5, 0., 0.5, 0.5)
         }
#print(plt.rcParams.keys())  # prints every parameter key if need to edit anyhthing else
plt.rcParams.update(params)



### plotting part


fig = plt.figure()
planet_names = ["Sun", "Mecury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
                "Uranus", "Neptune", "Pluto"]


for i in range(number_of_planets):
    print(i)
    planet_subplot = fig.add_subplot(2,5,i+1) ## specific for number of planets

    planet_subplot.plot (solar_system_dataframe.iloc[lambda x: x.index % number_of_planets == i]["X"],
                         solar_system_dataframe.iloc[lambda x: x.index % number_of_planets == i]["Y"])
    planet_subplot.set_xlabel('au')
    planet_subplot.set_ylabel('au')
    planet_subplot.set_title(planet_names[i] + " orbit")

plt.show()
fig.savefig ("Orbits_of_planets_x_y.png")