import pandas as pd
import numpy as np


import matplotlib.pyplot as plt


system_variables = pd.read_csv ("../data/Simulation_Results/system_variables_python.txt", sep= ",",
                                names= ["L_"])

print (system_variables)