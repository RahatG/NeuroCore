# src/config/settings.py

from pydantic_settings import BaseSettings
from dotenv import load_dotenv
import os

# Load environment variables from .env file
dotenv_path = os.path.join(os.path.dirname(__file__), '../.env')
load_dotenv(dotenv_path)

class Settings(BaseSettings):
    data_path: str = "/home/rahat/NeuroCore/EAI_Model/arxiver/data/train.parquet"
    model_output_path: str = "/home/rahat/NeuroCore/EAI_Model/model"
    optimizer: str = "Adam"
    learning_rate: float = 0.001
    epochs: int = 10
    secret_key: str = "EC57D15924DF4B95344A47E95C2C5"
    algorithm: str = "HS256"
    host: str = "0.0.0.0"
    port: int = 8000
    log_level: str = "DEBUG"
    database_uri: str = "sqlite:///neurocore.db"

    model_config = {
        "from_attributes": True,
        "env_file": "../.env",
        "protected_namespaces": ("settings_",),
    }

settings = Settings()
print(f"Settings Loaded: {settings.dict()}")
