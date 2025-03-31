import os
import json

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

    for i in files:
        print("User: ", i["user"])