import kagglehub

# Download latest version
path = kagglehub.dataset_download("fedesoriano/traffic-prediction-dataset")

print("Path to dataset files:", path)
