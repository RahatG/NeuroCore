import InterfaceEngine

def main():
    try:
        # Initialize InterfaceEngine
        data_path = "/home/rahat/NeuroCore/EAI_Model/arxiver/data/train.parquet"
        model_output_path = "/home/rahat/NeuroCore/EAI_Model/model"
        engine = InterfaceEngine.InterfaceEngine(data_path, model_output_path)
        print("InterfaceEngine initialized successfully.")

        # Perform a prediction
        sample_text = "This is a sample input text for prediction."
        prediction = engine.predict(sample_text)
        print(f"Prediction: {prediction}")

        # Start training
        epochs = 1
        engine.train(epochs)
        print(f"Training completed for {epochs} epoch(s).")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
