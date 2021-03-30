import pandas as pd
import numpy as np


import matplotlib.pyplot as plt
import matplotlib.animation as animation

### Tis part of the script reads the data from results.txt
### and stores it in an array of pandas dataframes called solar_system_iterations

inFile = open("../data/Simulation_Results/results_human_readable.txt",'r')
Solar_system_iterations=[]


all_planets_data_string = []

number_of_planets = 10
planet_colours = ['yellow' ,'gray' ,'red' ,'blue' ,'red' ,'green' ,'brown' , 'black' , 'blue', 'blue']

solar_system_iterations = {}

i = 0

for line in inFile:
    if len(line.strip()) == 0:
        solar_system = np.array(np.zeros(6))
        for planet in all_planets_data_string:
            chunks = planet.split(',')

            planet_array = np.asarray(chunks, dtype=np.float64)
            solar_system = np.vstack((solar_system, planet_array))

        solar_system = np.delete(solar_system, 0, 0)
        solar_system_iterations[i] = pd.DataFrame(data=solar_system, dtype=np.float64,
                                                  columns=["X", "Y", "Z", "V_x", "V_y", "V_z"])
        i += 1


        all_planets_data_string = []
    else:
        all_planets_data_string.append(line)


inFile.close()

print (len(solar_system_iterations))


print (solar_system_iterations[1]["X"])


### Now for the animation part

fig = plt.figure()
ax = plt.axes(xlim=(-40, 40), ylim=(-40, 40))


ax.set_facecolor("black") # black colour for
ax.axis('off')



line, = plt.plot([], [], marker='o', color=[], linestyle='None', ms = 1)

def init():
    line.set_data([], [])
    return line,
def animate(i):
    x = solar_system_iterations[i]["X"]
    y = solar_system_iterations[i]["Y"]
    z = planet_colours
    line.set_data(x, y, z)
    return line,


interval = 100  # ms
frames = len(solar_system_iterations) # number of frames

anim = animation.FuncAnimation(fig, animate, init_func=init,
                               frames= frames, blit=True)

writervideo = animation.FFMpegWriter(fps=60)

anim.save('solar_system.mp4',  writer=writervideo)
