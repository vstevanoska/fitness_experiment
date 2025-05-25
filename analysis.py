import os
import json
import matplotlib.pyplot as plt
import numpy as np
import math
from scipy.signal import find_peaks

def plot_value(title, file_id, y_axis1, y_axis2, y_axis3):

    # fig, axs = plt.subplots(3)
    plt.figure()
    # fig.suptitle(str("File id: " + str(file_id) + " " + title))
    plt.title(str("File id: " + str(file_id) + " " + title))

    plt.plot(list(range(len(y_axis1))), y_axis1, "r")
    plt.plot(list(range(len(y_axis2))), y_axis2, "g")
    plt.plot(list(range(len(y_axis3))), y_axis3, "b")

    # axs[0].plot(list(range(len(y_axis1))), y_axis1, "r")
    # axs[1].plot(list(range(len(y_axis2))), y_axis2, "g")
    # axs[2].plot(list(range(len(y_axis3))), y_axis3, "b")

    plt.show()

def find_threshold(files):

    avg_threshold_acc_x = 0
    avg_threshold_acc_y = 0
    avg_threshold_acc_z = 0
    avg_threshold_gyr_x = 0
    avg_threshold_gyr_y = 0
    avg_threshold_gyr_z = 0

    for f in files:

        x_coords_acc = []
        y_coords_acc = []
        z_coords_acc = []
        x_coords_gyr = []
        y_coords_gyr = []
        z_coords_gyr = []

        reps = f["numberOfReps"]
        freq = f["frequency"]

        for acc_measurement in f["accMeasurements"]:
            x_coords_acc.append(acc_measurement["x"])
            y_coords_acc.append(acc_measurement["y"])
            z_coords_acc.append(acc_measurement["z"])

        for gyr_measurement in f["gyrMeasurements"]:
            x_coords_gyr.append(gyr_measurement["x"])
            y_coords_gyr.append(gyr_measurement["y"])
            z_coords_gyr.append(gyr_measurement["z"])

        x_coords_acc = np.array(x_coords_acc)
        y_coords_acc = np.array(y_coords_acc)
        z_coords_acc = np.array(z_coords_acc)
        x_coords_gyr = np.array(x_coords_gyr)
        y_coords_gyr = np.array(y_coords_gyr)
        z_coords_gyr = np.array(z_coords_gyr)

        _, props_x_acc = find_peaks(x_coords_acc, height=x_coords_acc.min(), distance=round(freq, -1))
        _, props_y_acc = find_peaks(y_coords_acc, height=y_coords_acc.min(), distance=round(freq, -1))
        _, props_z_acc = find_peaks(z_coords_acc, height=z_coords_acc.min(), distance=round(freq, -1))
        _, props_x_gyr = find_peaks(x_coords_gyr, height=x_coords_gyr.min(), distance=round(freq, -1))
        _, props_y_gyr = find_peaks(y_coords_gyr, height=y_coords_gyr.min(), distance=round(freq, -1))
        _, props_z_gyr = find_peaks(z_coords_gyr, height=z_coords_gyr.min(), distance=round(freq, -1))

        peak_heights_x_acc = props_x_acc["peak_heights"]
        peak_heights_y_acc = props_y_acc["peak_heights"]
        peak_heights_z_acc = props_z_acc["peak_heights"]
        peak_heights_x_gyr = props_x_gyr["peak_heights"]
        peak_heights_y_gyr = props_y_gyr["peak_heights"]
        peak_heights_z_gyr = props_z_gyr["peak_heights"]

        for i in range(len(peak_heights_x_acc) - 1):
            for j in range(i + 1, len(peak_heights_x_acc)):
                temp = peak_heights_x_acc[i]
                peak_heights_x_acc[i] = peak_heights_x_acc[j]
                peak_heights_x_acc[j] = temp

        for i in range(len(peak_heights_y_acc) - 1):
            for j in range(i + 1, len(peak_heights_y_acc)):
                temp = peak_heights_y_acc[i]
                peak_heights_y_acc[i] = peak_heights_y_acc[j]
                peak_heights_y_acc[j] = temp

        for i in range(len(peak_heights_z_acc) - 1):
            for j in range(i + 1, len(peak_heights_z_acc)):
                temp = peak_heights_z_acc[i]
                peak_heights_z_acc[i] = peak_heights_z_acc[j]
                peak_heights_z_acc[j] = temp

        for i in range(len(peak_heights_x_gyr) - 1):
            for j in range(i + 1, len(peak_heights_x_gyr)):
                temp = peak_heights_x_gyr[i]
                peak_heights_x_gyr[i] = peak_heights_x_gyr[j]
                peak_heights_x_gyr[j] = temp

        for i in range(len(peak_heights_y_gyr) - 1):
            for j in range(i + 1, len(peak_heights_y_gyr)):
                temp = peak_heights_y_gyr[i]
                peak_heights_y_gyr[i] = peak_heights_y_gyr[j]
                peak_heights_y_gyr[j] = temp

        for i in range(len(peak_heights_z_gyr) - 1):
            for j in range(i + 1, len(peak_heights_z_gyr)):
                temp = peak_heights_z_gyr[i]
                peak_heights_z_gyr[i] = peak_heights_z_gyr[j]
                peak_heights_z_gyr[j] = temp

        #sortiranje potrebno ovde

        if (reps < len(peak_heights_x_acc)):
            peak_heights_x_acc = peak_heights_x_acc[:reps]

        if (reps < len(peak_heights_y_acc)):
            peak_heights_y_acc = peak_heights_y_acc[:reps]

        if (reps < len(peak_heights_z_acc)):
            peak_heights_z_acc = peak_heights_z_acc[:reps]

        if (reps < len(peak_heights_x_gyr)):
            peak_heights_x_gyr = peak_heights_x_gyr[:reps]

        if (reps < len(peak_heights_y_gyr)):
            peak_heights_y_gyr = peak_heights_y_gyr[:reps]

        if (reps < len(peak_heights_y_gyr)):
            peak_heights_y_gyr = peak_heights_y_gyr[:reps]

        avg_threshold_acc_x += peak_heights_x_acc[len(peak_heights_x_acc) - 1]
        avg_threshold_acc_y += peak_heights_y_acc[len(peak_heights_y_acc) - 1]
        avg_threshold_acc_z += peak_heights_z_acc[len(peak_heights_z_acc) - 1]
        avg_threshold_gyr_x += peak_heights_x_gyr[len(peak_heights_x_gyr) - 1]
        avg_threshold_gyr_y += peak_heights_y_gyr[len(peak_heights_y_gyr) - 1]
        avg_threshold_gyr_z += peak_heights_z_gyr[len(peak_heights_z_gyr) - 1]

    avg_threshold_acc_x /= len(files)
    avg_threshold_acc_y /= len(files)
    avg_threshold_acc_z /= len(files)
    avg_threshold_gyr_x /= len(files)
    avg_threshold_gyr_y /= len(files)
    avg_threshold_gyr_z /= len(files)

    print("Avg x acc: ", avg_threshold_acc_x)
    print("Avg y acc: ", avg_threshold_acc_y)
    print("Avg z acc: ", avg_threshold_acc_z)
    print("Avg x gyr: ", avg_threshold_gyr_x)
    print("Avg y gyr: ", avg_threshold_gyr_y)
    print("Avg z gyr: ", avg_threshold_gyr_z)

    # x = np.array(x)

    # peaks, properties = find_peaks(x, height=x.min(), distance=round(freq, -1))
    # peak_heights = properties["peak_heights"]

    # for i in range(len(peak_heights) - 1):
    #     for j in range(i + 1, len(peak_heights)):

    #         if (peak_heights[i] < peak_heights[j]):
    #             temp = peak_heights[i]
    #             peak_heights[i] = peak_heights[j]
    #             peak_heights[j] = temp

    #             temp = peaks[i]
    #             peaks[i] = peaks[j]
    #             peaks[j] = temp

    # if (reps < len(peak_heights)):
    #     print(peak_heights[reps])
    #     lower_boundary = peak_heights[reps]
    #     # peak_heights = peak_heights[:reps]
    #     # peaks = peaks[:reps]
    # else:
    #     # prominences = properties["prominences"]#doesnt exist
    #     # lower_boundary = prominences.max()
    #     minimal_peak = peak_heights.min()
    #     print("Minimal peak is: ", minimal_peak)

    #     peaks2, properties2 = find_peaks(x, height=(None, minimal_peak), distance=round(freq, -1))
    #     # peak_heights2 = properties2['peak_heights']

    #     lower_boundary = properties2['peak_heights'].max()


    # lower_bound = [lower_boundary] * len(x)
    # # lower_boundary = -10
    # # lower_bound = [-10] * len(x)

    # plt.title("Pospeškometer - os x - VS - vaja 1")
    # plt.figtext(0.37, 0.01, str("Prag: " + str(lower_boundary)))
    # plt.plot(x)
    # plt.plot(peaks, x[peaks], "x")
    # plt.plot(lower_bound, "--", color="gray")
    # plt.show()
        # plt.savefig("thresh_acc_y_VS_vaja1.png")

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


    ##Build profiles for each axis
    ##Average graph, min, max, avg value, std

    #Overhead triceps extension
    #Bicep curl
    #Tricep dumbbell kickback


    experiment_type = "Tricep dumbbell kickback"
    freq = 26

    i = 0

    while (i < len(files)):

        # if (files[i]["experimentType"] != experiment_type or files[i]["frequency"] != freq):
        if (files[i]["experimentType"] != experiment_type):
            del files[i]
            i -= 1

        i += 1

    find_threshold(files)

    x_coords_acc = []

    min_x_acc = 0
    max_x_acc = 0
    avg_x_acc = 0

    for f in files:
        for acc_measurement in f["accMeasurements"]:
                x_coords_acc.append(acc_measurement["x"])

                if (acc_measurement["x"] < min_x_acc):
                    min_x_acc = acc_measurement["x"]

                elif (acc_measurement["x"] > max_x_acc):
                    max_x_acc = acc_measurement["x"]

                avg_x_acc += acc_measurement["x"]

    avg_x_acc /= len(x_coords_acc)
    # std_x_acc = math.sqrt(abs(avg_x_acc) / len(x_coords_acc))
    std_x_acc = np.std(x_coords_acc)

    #find max count of number of reps
    numberOfReps = []
    
    for f in files:

        isFound = False

        for i in range(len(numberOfReps)):
            if (numberOfReps[i][0] == f["numberOfReps"]):
                isFound = True
                numberOfReps[i][1] += 1

        if (isFound is False):
            numberOfReps.append([f["numberOfReps"], 1])

    maxNumber = 0
    maxReps = 0

    for i in range(len(numberOfReps)):

        if (numberOfReps[i][1] > maxReps):
            
            maxNumber = numberOfReps[i][0]
            maxReps = numberOfReps[i][1]

    print("Max number is: ", maxNumber)

    subtext_string = "Število ponovitev: " + str(maxNumber) + "\nMin: " + str(round(min_x_acc, 4)) + " Max: " + str(round(max_x_acc, 4)) + "\nAvg: " + str(round(avg_x_acc, 4)) + " Std: " + str(round(std_x_acc, 4))

    x_coords_acc_graph = []

    plt.figure()

    for f in files:

        if (f["numberOfReps"] == maxNumber):

            x_temp = []

            for acc_measurement in f["accMeasurements"]:
                x_temp.append(acc_measurement["x"])

            x_coords_acc_graph.append(x_temp)

    x_avg = []

    length_of_arr = len(x_coords_acc_graph[0])

    for i in range(len(x_coords_acc_graph)):
        if (len(x_coords_acc_graph[i]) < length_of_arr):
            length_of_arr = len(x_coords_acc_graph[i])

    for j in range(length_of_arr):

        x_pos_avg = 0

        for i in range(len(x_coords_acc_graph)):
            x_pos_avg += x_coords_acc_graph[i][j]

        x_pos_avg /= len(x_coords_acc_graph)
        x_avg.append(x_pos_avg)

    # plot_peaks(x_avg, maxNumber, freq)

    timestamp_acc = list(range(len(x_avg)))

    plot_min = [min_x_acc] * len(timestamp_acc)
    plot_max = [max_x_acc] * len(timestamp_acc)
    plot_avg = [avg_x_acc] * len(timestamp_acc)
    plot_std = [avg_x_acc + std_x_acc] * len(timestamp_acc)
    plot_std2 = [avg_x_acc + ((-1) * std_x_acc)] * len(timestamp_acc)

    # plt.title("Povprečne meritve pospeškometra - os x - OC - vaja 3")
    # plt.figtext(0.37, 0.01, subtext_string)
    # plt.plot(timestamp_acc, x_avg, 'k')
    # plt.plot(timestamp_acc, plot_min, 'b')
    # plt.plot(timestamp_acc, plot_max, 'r')
    # plt.plot(timestamp_acc, plot_avg, 'g')
    # plt.plot(timestamp_acc, plot_std, 'c')
    # plt.plot(timestamp_acc, plot_std2, 'c')
    # plt.gca().get_xaxis().set_visible(False)

    # plt.savefig("avg_acc_x_OC_vaja3.png")
        

