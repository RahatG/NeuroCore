from pydantic import BaseModel

class PredictRequest(BaseModel):
    text: str

class TrainRequest(BaseModel):
    epochs: int
