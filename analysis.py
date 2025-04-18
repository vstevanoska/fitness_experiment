import os
import json
import matplotlib.pyplot as plt

if __name__ == '__main__':

    files = []

    user = input("Please input for which user you need analysis: ")

    data_path = "C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\git\\FitnessExperimentServer\\FitnessExperimentServer\\data"

    if user == "*":
        
        for i in os.listdir(data_path):
            with open((data_path + "\\" + i), "r") as json_file:
                files.append(json.load(json_file))
        
    else:
        
        for i in os.listdir(data_path):
            if (os.path.isfile(os.path.join(data_path, i)) and user in i):
                
                with open((data_path + "\\" + i), "r") as json_file:
                    files.append(json.load(json_file))

    #x is time, y is value

    #separate graph for each coordinate
    #graphs for different frequencies: 6 graphs
    #graphs for different speeds: 6 graphs + 6 = 12 graphs

    x_coords_acc = []
    y_coords_acc = []
    z_coords_acc = []

    for f in files:

        if f["frequency"] == 26:

            x_temp = []
            y_temp = []
            z_temp = []

            for j in range(len(f["accMeasurements"])):

                x_temp.append(f["accMeasurements"][j]["x"])
                y_temp.append(f["accMeasurements"][j]["y"])
                z_temp.append(f["accMeasurements"][j]["z"])

            x_coords_acc.append(x_temp)
            y_coords_acc.append(y_temp)
            z_coords_acc.append(z_temp)

    time_acc = list(range(len(x_coords_acc[0])))

    x_avg_plot_acc = [0] * len(x_coords_acc[0])
    y_avg_plot_acc = [0] * len(y_coords_acc[0])
    z_avg_plot_acc = [0] * len(z_coords_acc[0])

    x_avg_acc = 0
    y_avg_acc = 0
    z_avg_acc = 0

    #min, max, std

    for j in range(len(x_coords_acc[0])):
        for i in range(len(x_coords_acc)):
            x_avg_plot_acc[j] += x_coords_acc[i][j]
            x_avg_acc += x_coords_acc[i][j]

            y_avg_plot_acc[j] += y_coords_acc[i][j]
            y_avg_acc += y_coords_acc[i][j]

            z_avg_plot_acc[j] += z_coords_acc[i][j]
            z_avg_acc += z_coords_acc[i][j]

        x_avg_plot_acc[j] /= len(x_coords_acc)
        y_avg_plot_acc[j] /= len(y_coords_acc)
        z_avg_plot_acc[j] /= len(z_coords_acc)

    x_avg_acc /= (len(x_coords_acc) * len(x_coords_acc[0]))
    y_avg_acc /= (len(y_coords_acc) * len(y_coords_acc[0]))
    z_avg_acc /= (len(z_coords_acc) * len(z_coords_acc[0]))

    x_avg = [x_avg_acc] * len(time_acc)

    plt.figure()

    for i in range(len(x_coords_acc)):

        plt.plot(time_acc, x_coords_acc[i])

    plt.plot(time_acc, x_avg_plot_acc, "r")
    plt.plot(time_acc, x_avg, "g")

    plt.show()
