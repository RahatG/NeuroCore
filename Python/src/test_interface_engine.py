# test_interface_engine.py

from InterfaceEngine import DataLoader, InterfaceEngine

def main():
    # Initialize DataLoader with a sample data path
    data_path = "/home/rahat/arxiver/data/train.parquet"  # Ensure this path is correct
    try:
        data_loader = DataLoader(data_path)
        data = data_loader.load_data()
        print(f"Loaded {len(data)} data entries.")
    except Exception as e:
        print(f"DataLoader failed: {e}")
        return

    # Initialize InterfaceEngine with data and model output paths
    model_output_path = "/home/rahat/NeuroCore/Model/"  # Ensure this path is correct
    try:
        engine = InterfaceEngine(data_path, model_output_path)
        print("InterfaceEngine initialized successfully.")
    except Exception as e:
        print(f"InterfaceEngine initialization failed: {e}")
        return

    # Test the predict method
    sample_text = "This is a sample input text for prediction."
    try:
        predictions = engine.predict(sample_text)
        print(f"Predictions for '{sample_text}': {predictions}")
    except Exception as e:
        print(f"Prediction failed: {e}")

    # Test the train method
    epochs = 1  # Start with 1 epoch for testing
    try:
        engine.train(epochs)
        print(f"Training completed for {epochs} epoch(s).")
    except Exception as e:
        print(f"Training failed: {e}")

if __name__ == "__main__":
    main()
