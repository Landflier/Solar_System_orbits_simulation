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

print (len(solar_system_dataframe))


### Now for the animation part

fig = plt.figure()
ax = plt.axes(xlim=(-4, 4), ylim=(-4, 4))


#ax.axis('off')


frames = int(len(solar_system_dataframe)/number_of_planets) # number of frames

color_data= np.array([planet_colours] * frames)
x_initial = solar_system_dataframe.iloc[0:10]["X"]
y_intial = solar_system_dataframe.iloc[0:10]["Y"]


scatter_plot = ax.scatter(x_initial, y_intial, marker='o',
                          c=planet_colours, linestyle='None', s = 1, cmap='viridis')

def animate(frame_number, color_data, scatter_plot):
    x = solar_system_dataframe.iloc[number_of_planets*frame_number:number_of_planets*(frame_number+1)]["X"]
    y = solar_system_dataframe.iloc[number_of_planets*frame_number:number_of_planets*(frame_number+1)]["Y"]
    points = np.hstack((x, y)).reshape(number_of_planets,2)
    scatter_plot.set_offsets(points)

    scatter_plot.set_array(color_data[frame_number])
    return scatter_plot,

color_data = np.vstack(([planet_colours] * frames) )


anim = animation.FuncAnimation(fig, animate, frames= frames, blit=True,
                               fargs=(color_data, scatter_plot))

writervideo = animation.FFMpegWriter(fps=60)

anim.save('solar_system.mp4')