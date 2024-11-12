import pandas as pd
from ..Python.src.services.data_service import DataService
from ..Python.src.nlp.processor import Processor

def preprocess_data():
    data_service = DataService("/home/rahat/NeuroCore/EAI_Model/arxiver/data/train.parquet")
    data = data_service.get_data()
    processor = Processor("/home/rahat/NeuroCore/EAI_Model/arxiver/data/train.parquet", "/home/rahat/NeuroCore/EAI_Model/model")
    processed_data = [processor.process(text) for text in data]
    # Save or further process as needed

if __name__ == "__main__":
    preprocess_data()
