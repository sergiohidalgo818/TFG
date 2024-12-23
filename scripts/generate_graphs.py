import os
import pandas as pd
import matplotlib.pyplot as plt
import statistics

def plot_model_data(directory:str, filename:str, type_model:str):

    special_dir = directory.split("/")[-2]
    if not os.path.exists("graphs/executions_"+type_model+"/" + special_dir):
        os.makedirs("graphs/executions_"+type_model+"/" + special_dir)

    
    print("ploting " + filename)
    data_frame = pd.read_csv(directory + filename, sep=";")
    data_frame = data_frame[['x', 'time']]

    plt.figure( figsize=(12,6) )

    plt.plot( data_frame["time"], data_frame["x"]) 
    plt.xlim((data_frame['time'].min(), data_frame['time'].max()))
    
    name = filename.split('.')[0]


    plt.savefig("graphs/executions_"+type_model+"/"  + special_dir + "/"+name+ '.png')
    plt.close()


def plot_speed_data(path, type_model:str):


    if not os.path.exists("graphs/timings_"+type_model+"/"):
        os.makedirs("graphs/timings_"+type_model+"/")

    files = os.listdir(path)

    data_frames = list()
    print("ploting files in " + path)
    labels = list()
    for filename in files:
        labels.append(filename)

        data_frame = pd.read_csv(path + "/" + filename, sep=";")
        data_frames.append(data_frame)


    for col_name in data_frames[0].columns:
        
        data = list()
        for data_frame in data_frames:
            data.append(statistics.mean(data_frame[col_name].values))



        fig, ax = plt.subplots(1, 1) 
        
        plt.bar(labels,  data, width = 0.4) 

        ax.set_xlabel(col_name) 
        ax.set_ylabel("seconds")

        plt.savefig("graphs/timings_"+type_model+"/"+col_name+ '.png')
        plt.close()

