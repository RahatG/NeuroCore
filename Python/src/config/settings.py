from pydantic import BaseSettings

class Settings(BaseSettings):
    data_path: str
    model_output_path: str
    optimizer: str
    learning_rate: float
    epochs: int
    secret_key: str
    algorithm: str = "HS256"

    class Config:
        env_file = "../.env"

settings = Settings()
