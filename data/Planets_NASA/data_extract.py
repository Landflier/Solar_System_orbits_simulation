import glob
import numpy as np
import pandas as pd


buffer= []
files_input = []

Objects     = ["sun", "mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto"]
Objects_mass= [1988500e+24, 3.302e+23, 48.685e+23, 5.97219e+24, 6.4171e+23, 1898.13e+24, 5.6834e+26, 86.813e+24, 1.0241e+26, 1.307e+22]

for filepath in glob.iglob(r'*.txt'):

    inFile = open(filepath,'r')
    for line in inFile:
        if "Mass" in line:
            print(line)
        if line.startswith("$$SOE"):
            buffer = [""]

        elif line.startswith("$$EOE"):
             buffer = []

        elif buffer:
             files_input.append(line)
    inFile.close()

csv_input= np.array(np.zeros(6)) # intialize with zeroes, so we can use vstack method
                                 # dimension is 6, 3 position+ 3 momentum

for x in files_input:
    chunks = x.split(',')

    ## read only momentum and postion
    del chunks[0:2]
    del chunks[-4:-1]
    chunks.pop() ## pop last '\n' element


    planet_array = np.asarray(chunks, dtype=np.float64)
    print(planet_array)
    csv_input = np.vstack((csv_input,planet_array))

csv_input = np.delete(csv_input, 0, 0)
df = pd.DataFrame(data=csv_input, dtype=np.float64 )



# add distance to coordinate center,  by it, then remove the column
df.columns = ["X", "Y", "Z", "V_x", "V_y", "V_z"]
df["RG"] = np.sqrt(df["X"]**2 + df["Y"]**2 + df["Z"]**2)
df.sort_values("RG", inplace=True)
df.drop(columns=['RG'], inplace=True)

# dirty add mass of objects
df["mass"]= Objects_mass

np.savetxt(r'Solar_system_bodies.txt', df.values, delimiter=',')

df.insert(0, 'name', Objects)

print (df)
df.to_csv("Solar_system_bodies.csv", float_format=np.float64, index=False)