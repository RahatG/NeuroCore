from pydantic import BaseModel
from typing import List

class PredictResponse(BaseModel):
    prediction: List[float]

class TrainResponse(BaseModel):
    message: str
