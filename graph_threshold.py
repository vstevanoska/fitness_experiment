import os
import json
import matplotlib.pyplot as plt
import numpy as np
import math
from scipy.signal import find_peaks

if __name__ == '__main__':

    #OC_2025-4-19-18-34-59
    #VS_2025-4-18-16-57-49

    filename = "VS_2025-4-18-16-57-49.json"

    data_path = "C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\git\\FitnessExperimentServer\\FitnessExperimentServer\\data\\"

    with open((data_path + filename), 'r') as json_file:
        file = json.load(json_file)

    coords = []

    for measurement in file["gyrMeasurements"]:
        coords.append(measurement["z"])

    timestamp_coords = list(range(len(coords)))

    threshold_coords = [195.1478] * len(coords)

    plt.figure()

    plt.title("VS_2025-4-18-16-57-49.json")
    plt.plot(timestamp_coords, coords)
    plt.plot(threshold_coords, "--", color="black")
    plt.gca().get_xaxis().set_visible(False)
    # plt.show()

    plt.savefig("thr_vs_z_vaja3_gyr.png")
        

